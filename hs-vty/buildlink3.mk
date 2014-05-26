# $NetBSD: buildlink3.mk,v 1.6 2014/05/26 22:08:05 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vty

.if !defined(HS_VTY_BUILDLINK3_MK)
HS_VTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vty+=	hs-vty>=4.7.0
BUILDLINK_PKGSRCDIR.hs-vty?=	../../wip/hs-vty

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parallel/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vty
