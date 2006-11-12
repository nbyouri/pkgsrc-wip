/*	$NetBSD: whereis.c,v 1.3 2006/11/12 17:45:39 cheusov Exp $	*/

/*-
 * Copyright (c) 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>

#include <sys/param.h>
#include <sys/stat.h>
#if !defined(__linux__) && !defined(__INTERIX)
#include <sys/sysctl.h>
#endif

#include <err.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void usage(void) __attribute__((__noreturn__));

char *__progname;

int
main(int argc, char *argv[])
{
	struct stat sb;
	size_t len;
	int ch, mib[2];
	char *p, *std, path[MAXPATHLEN];
	const char *t;
	int which;
	int useenvpath, found = 0;
	gid_t egid = getegid();
	uid_t euid = geteuid();

	__progname = basename(argv[0]);
	which = strcmp(__progname, "which") == 0;
	useenvpath = which;

	/* To make access(2) do what we want */
	if (setgid(egid) == -1)
		err(1, "Can't set gid to %lu", (unsigned long)egid);
	if (setuid(euid) == -1)
		err(1, "Can't set uid to %lu", (unsigned long)euid);

	while ((ch = getopt(argc, argv, "ap")) != -1)
		switch (ch) {
		case 'a':
			which = 0;
			break;
		case 'p':
			useenvpath = 1;	/* use environment for PATH */
			break;

		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;

	if (argc == 0)
		usage();

 	if (useenvpath) {
 		if ((std = getenv("PATH")) == NULL)
 			errx(1, "PATH environment variable is not set");
	} else {
#ifndef __INTERIX
#ifdef __linux__
#include <paths.h>
	if ((std = malloc(MAXPATHLEN)) == NULL)
		err(1, NULL);
	(void)strncpy(std, _PATH_DEFPATH, MAXPATHLEN);
#else
#ifndef CTL_USER
#define CTL_USER	8
#endif
#ifndef USER_CS_PATH
#define	USER_CS_PATH	1
#endif
		/* Retrieve the standard path. */
		mib[0] = CTL_USER;
		mib[1] = USER_CS_PATH;
		if (sysctl(mib, 2, NULL, &len, NULL, 0) == -1)
			err(1, "sysctl: user.cs_path");
		if (len == 0)
			errx(1, "sysctl: user.cs_path (zero length)");
		if ((std = malloc(len)) == NULL)
			err(1, NULL);
		if (sysctl(mib, 2, std, &len, NULL, 0) == -1)
			err(1, "sysctl: user.cs_path");
#endif /* not Linux */
#endif /* Interix */
	}

	/* For each path, for each program... */
	for (; *argv; ++argv)
		for (p = std; p; p && (*p++ = ':')) {
			t = p;
			if ((p = strchr(p, ':')) != NULL) {
				*p = '\0';
				if (t == p)
					t = ".";
			} else
				if (strlen(t) == 0)
					t = ".";
			(void)snprintf(path, sizeof(path), "%s/%s", t, *argv);
			if (stat(path, &sb) == -1)
				continue;
			if (!S_ISREG(sb.st_mode))
				continue;
			if (access(path, X_OK) == -1)
				continue;
			(void)printf("%s\n", path);
			found++;
			if (which)
				break;
		}
	
	return ((found == 0) ? 3 : ((found >= argc) ? 0 : 2));
}

static void
usage(void)
{

/*	(void)fprintf(stderr, "Usage: %s [-ap] program [...]\n", getprogname()); */
	(void)fprintf(stderr, "Usage: %s [-ap] program [...]\n", __progname);
	exit(1);
}
