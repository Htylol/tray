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

  void (*cb)(struct tray_menu *);
  void *context;

  struct tray_menu *submenu;
};

void tray_update(struct tray *tray);

int tray_init(struct tray *tray);
int tray_loop(int blocking);
void tray_update(struct tray *tray);
void tray_exit();
#ifdef __cplusplus
}
#endif

#endif /* TRAY_H */
