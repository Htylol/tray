#include "tray/tray.h"
#include <filesystem>
#include <stdlib.h>

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main() {
  setlocale (LC_ALL, "");
  bindtextdomain ("tray", "../locales");
  textdomain ("tray");

  std::string icon_name = "../img/gui/portproton_tray.svg";
  auto icon_path = std::filesystem::current_path() / icon_name;

  trays::Menu q;
  q.text_ = _("WINEFILE");
  trays::Menu w;
  w.text_ = _("TASKMGR");
  trays::Menu e;
  e.text_ = _("CHANGELOG");
  trays::Menu r;
  r.text_ = _("FORCE EXIT");

  q.on_click_ = [](auto) { system("bash -c pw_tray_winefile &"); };
  w.on_click_ = [](auto) { system("bash -c pw_tray_taskmgr &"); };
  e.on_click_ = [](auto) { system("bash -c open_changelog &"); };
  r.on_click_ = [](auto) { system("bash -c kill_portwine &"); tray_exit(); };
  trays::Tray t{icon_path.string(), {q,w,e,r}};

  t.run();
}
