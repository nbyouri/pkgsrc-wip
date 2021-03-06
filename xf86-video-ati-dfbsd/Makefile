# $NetBSD: Makefile,v 1.42 2017/03/16 12:04:25 wiz Exp $

DISTNAME=	xf86-video-ati-7.9.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Radeon video driver

CONFLICTS+=	xf86-video-ati6-[0-9]*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-ati
PKG_SUPPORTED_OPTIONS=  debug	

.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--enable-glamor

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-O0 -g3
.endif

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../devel/xorg-util-macros/buildlink3.mk"

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.18.1
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.58
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
