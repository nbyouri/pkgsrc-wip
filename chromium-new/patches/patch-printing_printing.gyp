$NetBSD$

--- printing/printing.gyp.orig	2016-06-24 01:02:26.000000000 +0000
+++ printing/printing.gyp
@@ -187,7 +187,7 @@
             'backend/print_backend_chromeos.cc',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or os_bsd == 1) and chromeos==0', {
           'sources': [
             'printing_context_linux.cc',
             'printing_context_linux.h',
