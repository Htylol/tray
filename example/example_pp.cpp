#include "tray/tray.h"
#include <stdlib.h>

int main() {
  trays::Menu m;
  m.text_ = "Open work dir";
  m.on_click_ = [](auto) { system("start ."); };
  trays::Tray t{"icon.ico", {m}};
  //   t.add(m);
  t.run();
}