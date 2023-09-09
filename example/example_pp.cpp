#include "tray/tray.h"
#include <filesystem>
#include <stdlib.h>

int main() {
  trays::Menu m;
  m.text_ = "Open work dir";

  // linux: png, svg
  std::string icon_name = "icon.png";

  // absolute path for linux.
  auto icon_path =std::filesystem::current_path() / icon_name;
  #ifdef _WIN32
  m.on_click_ = [](auto) { system("start ."); };
  #else
  m.on_click_ = [](auto) { system("open ."); };
  #endif

  trays::Tray t{icon_path.string(), {m}};
  //   t.add(m);
  t.run();
}