# $NetBSD$

DISTNAME=	libretro-parallel-n64-20170410
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core for Nintendo 64 emulation
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	parallel-n64
GITHUB_TAG=	571a477b79d57c10846fbfbdba9c6447f8d54cb9

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		Makefile
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "options.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/parallel_n64_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/parallel_n64_libretro.so

.include "../../mk/bsd.pkg.mk"
