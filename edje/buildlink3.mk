# $NetBSD: buildlink3.mk,v 1.3 2004/10/15 22:32:39 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EDJE_BUILDLINK3_MK:=	${EDJE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	edje
.endif

BUILDLINK_PACKAGES+=	edje

.if !empty(EDJE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.edje+=	edje>=0.5.0
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje
.endif	# EDJE_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../wip/embryo/buildlink3.mk"
.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
