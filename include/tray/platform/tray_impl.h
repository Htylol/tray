#include "tray/tray_raw.h"
#if defined(TRAY_APPINDICATOR)
#include "linux.h"
#elif defined(TRAY_APPKIT)
#include "macos.h"
#elif defined(_WIN32)
#include "windows.h"
#else
static_assert(false, "unknow platform");
#endif