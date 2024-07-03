#include "tray/tray.h"
#include <filesystem>
#include <stdlib.h>

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main() {

  setlocale (LC_ALL, "");
  bindtextdomain ("tray", getenv("PWD"));
  textdomain ("tray");

  trays::Menu q;
  q.text_ = _("WINEFILE");
  trays::Menu w;
  w.text_ = _("TASKMGR");
  trays::Menu e;
  e.text_ = _("CHANGELOG");

  // linux: png, svg
  std::string icon_name = "portproton_tray.svg";

  // absolute path for linux.
  auto icon_path =std::filesystem::current_path() / icon_name;
  q.on_click_ = [](auto) { system("bash -c pw_tray_winefile &"); };
  w.on_click_ = [](auto) { system("bash -c pw_tray_taskmgr &"); };
  e.on_click_ = [](auto) { system("bash -c open_changelog &"); };

  trays::Tray t{icon_path.string(), {q,w,e}};

  t.run();
}
