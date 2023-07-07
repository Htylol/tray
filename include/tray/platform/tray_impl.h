#include "tray/tray_raw.h"
#if defined(__linux__)
#include "linux.h"
#elif defined(TARGET_OS_MAC)
#include "macos.h"
#elif defined(_WIN32)
#include "windows.h"
#else
static_assert(false, "unknow platform");
#endif