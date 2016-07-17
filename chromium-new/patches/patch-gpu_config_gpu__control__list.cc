$NetBSD$

--- gpu/config/gpu_control_list.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ gpu/config/gpu_control_list.cc
@@ -17,7 +17,11 @@
 #include "base/sys_info.h"
 #include "gpu/config/gpu_info.h"
 #include "gpu/config/gpu_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace gpu {
 namespace {
