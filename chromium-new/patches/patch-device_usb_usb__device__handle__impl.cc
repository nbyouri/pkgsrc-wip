$NetBSD$

--- device/usb/usb_device_handle_impl.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ device/usb/usb_device_handle_impl.cc
@@ -24,7 +24,11 @@
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
 #include "net/base/io_buffer.h"
-#include "third_party/libusb/src/libusb/libusb.h"
+#if defined(OS_FREEBSD)
+#  include "libusb.h"
+#else
+#  include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
