# $Id: Makefile,v 1.95 2003/04/16 17:38:26 xtraeme Exp $
# $NetBSD: Makefile,v 1.95 2003/04/16 17:38:26 xtraeme Exp $

COMMENT=	WIP pkgsrc packages

SUBDIR+=	PPower4
SUBDIR+=	adodb
SUBDIR+=	allegro
SUBDIR+=	aolserver
SUBDIR+=	ap-bandwidth
SUBDIR+=	autoproject
SUBDIR+=	beaver
SUBDIR+=	billardgl
SUBDIR+=	byacc
SUBDIR+=	celestia
SUBDIR+=	chksniff
SUBDIR+=	cvsd
SUBDIR+=	devhelp
SUBDIR+=	drweb
SUBDIR+=	gkrellm2
SUBDIR+=	gkrellm2-flynn
SUBDIR+=	gkrellm2-launch
SUBDIR+=	gkrellm2-leds
SUBDIR+=	gkrellm2-multiping
SUBDIR+=	gkrellm2-server
SUBDIR+=	gkrellm2-share
SUBDIR+=	gkrellm2-snmp
SUBDIR+=	gkrellm2-volume
SUBDIR+=	gkrellm2-xmms
SUBDIR+=	golem
SUBDIR+=	gstreamer
SUBDIR+=	gstreamer-player
SUBDIR+=	gstreamer-plugins
SUBDIR+=	gtetrinet2
SUBDIR+=	gtk-sharp
SUBDIR+=	gtkglarea2
SUBDIR+=	gtranslator
SUBDIR+=	honeyd-arpd
SUBDIR+=	httrack
SUBDIR+=	ices
SUBDIR+=	ickle
SUBDIR+=	idled
SUBDIR+=	ike-scan
SUBDIR+=	ion-devel
SUBDIR+=	ion-dock
SUBDIR+=	jdk-openjit
SUBDIR+=	jdk12
SUBDIR+=	jdk12-openjit
SUBDIR+=	jdk13
SUBDIR+=	jdk13-openjit
SUBDIR+=	liquidwar
SUBDIR+=	mailfilter
SUBDIR+=	mcats
SUBDIR+=	mcats-iodbc
SUBDIR+=	mopac
SUBDIR+=	nagios-base
SUBDIR+=	nagios-plugin-ldap
SUBDIR+=	nagios-plugin-mysql
SUBDIR+=	nagios-plugin-pgsql
SUBDIR+=	nagios-plugin-snmp
SUBDIR+=	nagios-plugins
SUBDIR+=	navigatrix
SUBDIR+=	nvtv
SUBDIR+=	p5-Chart
SUBDIR+=	p5-Net-Jabber
SUBDIR+=	p5-Unicode-String
SUBDIR+=	p5-XML-Stream
SUBDIR+=	perltidy
SUBDIR+=	poedit
SUBDIR+=	pts
SUBDIR+=	py-ORBit
SUBDIR+=	py-OpenGL
SUBDIR+=	py-PgSQL
SUBDIR+=	py-csv
SUBDIR+=	py-gnome2
SUBDIR+=	py-gnosis-utils
SUBDIR+=	py-gtk2
SUBDIR+=	py-spreadmodule
SUBDIR+=	scm
SUBDIR+=	shoutcast
SUBDIR+=	tex-foiltex
SUBDIR+=	umix
SUBDIR+=	vim-gtk2
SUBDIR+=	xawtv
SUBDIR+=	xevil
SUBDIR+=	puf
SUBDIR+=	SDL_mm
SUBDIR+=	fluxconf
SUBDIR+=	mplayerplugin
SUBDIR+=	streamripper
SUBDIR+=	tsclient
SUBDIR+=	dovecot
SUBDIR+=	directfb
SUBDIR+=	geeklog
SUBDIR+=	lpe
SUBDIR+=	gdrdao
SUBDIR+=	dircproxy
SUBDIR+=	totem
SUBDIR+=	p5-HTTP-GHTTP
SUBDIR+=	pixieplus

.include "../mk/bsd.pkg.subdir.mk"
