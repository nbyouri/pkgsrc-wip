# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Tue Sep 13 11:08:59 CDT 2016               #
###########################################################

DISTNAME=	pbcopper-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=PacificBiosciences/}
GITHUB_PROJECT=	pbcopper
GITHUB_TAG=	ce9a4b6d836d53997d7acce6b5dceaa8bb8f7c22

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	https://github.com/PacificBiosciences/pbcopper
COMMENT=	Core C++ library for data structures, algorithms, and utilities
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pax
USE_CMAKE=	yes
GCC_REQD=	4.9	# pbcopper requires 4.9 due to use of json

MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-O2

WRKSRC=		${WRKDIR}/pbcopper-${GITHUB_TAG}

PORTVERSION=	2016.09.13

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && pax -rw . ${DESTDIR}${PREFIX}/include

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
