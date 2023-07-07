#include "tray/tray.h"
#include <filesystem>
#include <stdlib.h>

int main() {
  trays::Menu m;
  m.text_ = "Open work dir";
  m.on_click_ = [](auto) { system("open ."); };

  // absolute path for linux.
  // linux: png, svg
  std::string icon_name = "icon.png";
  auto icon_path =std::filesystem::current_path() / icon_name;
  trays::Tray t{icon_path.string(), {m}};
  //   t.add(m);
  t.run();
}