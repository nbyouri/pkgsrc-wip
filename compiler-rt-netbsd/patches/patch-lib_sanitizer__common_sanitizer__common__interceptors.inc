$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-06-12 15:01:29.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -3799,6 +3799,7 @@ INTERCEPTOR(int, pthread_mutex_lock, voi
   COMMON_INTERCEPTOR_ENTER(ctx, pthread_mutex_lock, m);
   COMMON_INTERCEPTOR_MUTEX_PRE_LOCK(ctx, m);
   int res = REAL(pthread_mutex_lock)(m);
+
   if (res == errno_EOWNERDEAD)
     COMMON_INTERCEPTOR_MUTEX_REPAIR(ctx, m);
   if (res == 0 || res == errno_EOWNERDEAD)
