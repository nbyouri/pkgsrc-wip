$NetBSD$

--- gpu/config/gpu_test_config.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ gpu/config/gpu_test_config.cc
@@ -26,7 +26,7 @@ namespace {
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
@@ -254,6 +254,10 @@ bool GPUTestBotConfig::LoadCurrentConfig
   bool rt;
   if (gpu_info == NULL) {
     GPUInfo my_gpu_info;
+#if defined(OS_FREEBSD)
+    rt = false;
+    LOG(WARNING) << "CollectGpuID not present on FreeBSD";
+#else
     CollectInfoResult result = CollectGpuID(
         &my_gpu_info.gpu.vendor_id, &my_gpu_info.gpu.device_id);
     if (result != kCollectInfoSuccess) {
@@ -263,6 +267,7 @@ bool GPUTestBotConfig::LoadCurrentConfig
     } else {
       rt = SetGPUInfo(my_gpu_info);
     }
+#endif
   } else {
     rt = SetGPUInfo(*gpu_info);
   }
