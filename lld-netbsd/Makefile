# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	lld-5.0.0
CATEGORIES=	devel

SVN_REPOSITORIES=	lld
SVN_REPO.lld=		http://llvm.org/svn/llvm-project/lld/trunk
SVN_REVISION.lld=	305636

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lld.llvm.org/
COMMENT=	The LLVM Linker
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-netbsd
.include "../../wip/llvm-netbsd/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
