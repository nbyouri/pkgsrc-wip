# $NetBSD: buildlink2.mk,v 1.4 2003/06/25 06:52:46 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-mcs-plugins.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_MCS_PLUGINS_BUILDLINK2_MK)
XFCE4_MCS_PLUGINS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-mcs-plugins
BUILDLINK_DEPENDS.xfce4-mcs-plugins?=		xfce4-mcs-plugins>=3.91.0
BUILDLINK_PKGSRCDIR.xfce4-mcs-plugins?=		../../wip/xfce4-mcs-plugins

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-mcs-plugins=xfce4-mcs-plugins
BUILDLINK_PREFIX.xfce4-mcs-plugins_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-mcs-plugins+=	lib/xfce4/mcs-plugins/keyboard_plugin.*
BUILDLINK_FILES.xfce4-mcs-plugins+=	lib/xfce4/mcs-plugins/mouse_plugin.*
BUILDLINK_FILES.xfce4-mcs-plugins+=	lib/xfce4/mcs-plugins/ui_plugin.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wip/xfce4-mcs-manager/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-mcs-plugins-buildlink

xfce4-mcs-plugins-buildlink: _BUILDLINK_USE

.endif	# XFCE4_MCS_PLUGINS_BUILDLINK2_MK
