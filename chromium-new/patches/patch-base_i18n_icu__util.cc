$NetBSD$

--- base/i18n/icu_util.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/i18n/icu_util.cc
@@ -36,10 +36,6 @@
 #include "base/mac/foundation_util.h"
 #endif
 
-#define ICU_UTIL_DATA_FILE   0
-#define ICU_UTIL_DATA_SHARED 1
-#define ICU_UTIL_DATA_STATIC 2
-
 namespace base {
 namespace i18n {
 
