# $NetBSD$

DISTNAME=	yarl-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yarl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/yarl/
COMMENT=	Yet another URL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-multidict>=2.0:../../wip/py-multidict

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
