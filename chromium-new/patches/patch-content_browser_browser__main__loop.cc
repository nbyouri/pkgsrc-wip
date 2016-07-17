$NetBSD$

--- content/browser/browser_main_loop.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/browser_main_loop.cc
@@ -191,7 +191,7 @@
 namespace content {
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const base::CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   base::FilePath sandbox_binary;
@@ -438,7 +438,7 @@ void BrowserMainLoop::EarlyInitializatio
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
   TRACK_SCOPED_REGION("Startup", "BrowserMainLoop::EarlyInitialization");
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
