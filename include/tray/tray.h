#ifndef TRAY_H
#define TRAY_H
#if defined(__cplusplus)
extern "C" {
#endif
struct tray_menu;

struct tray {
  char *icon;
  struct tray_menu *menu;
};

struct tray_menu {
  char *text;
  int disabled;
  int checked;

  void (*cb)(struct tray_menu *);
  void *context;

  struct tray_menu *submenu;
};

static void tray_update(struct tray *tray);

#if defined(TRAY_APPINDICATOR)
#include "platform/linux.h"
#elif defined(TRAY_APPKIT)
#include "platform/macos.h"
#elif defined(_WIN32)
#include "platform/windows.h"
#else
static_assert(false,"unknow platform");
#endif

#ifdef __cplusplus
}
#endif

#endif /* TRAY_H */
