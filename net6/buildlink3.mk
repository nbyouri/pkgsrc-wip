# $NetBSD: buildlink3.mk,v 1.5 2006/10/25 01:53:12 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NET6_BUILDLINK3_MK:=	${NET6_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	net6
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnet6}
BUILDLINK_PACKAGES+=	net6
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}net6

.if !empty(NET6_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.net6+=	net6>=1.2.1
BUILDLINK_PKGSRCDIR.net6?=	../../wip/net6
.endif	# NET6_BUILDLINK3_MK

.include "../../devel/libsigc++2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
