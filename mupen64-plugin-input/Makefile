# $NetBSD: Makefile,v 1.10 2009/02/15 13:39:31 thomasklausner Exp $
#

DISTNAME=	mupen64_input
PKGNAME=	${DISTNAME:S/_input/-plugin-input-1.1/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Input plugin for mupen64 emulator

BUILD_DEPENDS+=	mupen64-base-[0-9]*:../../wip/mupen64-base

CPPFLAGS+=	-fPIC

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
