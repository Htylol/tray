#include "tray/tray.h"

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

trays::Tray::Tray(std::string icon_path, std::vector<Menu> menus)
    : icon_(icon_path) {
  for (auto m : menus) {
    add(m);
  }

  setlocale (LC_ALL, "");
  bindtextdomain ("tray", getenv("PWD"));
  textdomain ("tray");

  Menu exit;
  exit.on_click_ = [](Menu *) { system("bash -c tray_icon_click_exit"); tray_exit(); };
  exit.text_ = _("FORCE EXIT");
  add(exit);

  tray_.icon = &icon_path[0];
  tray_init(&tray_);

  // this will not change content of menu.
  // maybe we don't have to keep resource for title for build is finished.
  // for(auto &m:menus_){
  //   m->text_ = "FSDFSDFSDF";
  // }

  // this too.
  // tray_.menu = nullptr;

  // what we need to keep it menu* and it's callback.
  // you can throw away anythings others.
}
void trays::Tray::run() {
  while (!tray_loop(1)) {
    ;
  }
}
void trays::Tray::add(Menu menu) {
  if (!raw_menus_.empty()) {
    raw_menus_.pop_back();
  }
  auto ptr = std::make_unique<Menu>(menu);
  tray_menu me{};
  me.context = ptr.get();
  me.text = &ptr->text_[0];

  me.cb = [](tray_menu *mem) {
    auto menu_pp = reinterpret_cast<Menu *>(mem->context);
    menu_pp->on_click_(menu_pp);
  };
  menus_.push_back(std::move(ptr));
  raw_menus_.push_back(me);
  raw_menus_.push_back({});
  tray_.menu = raw_menus_.data();
  if (init_finished_) {
    tray_update(&tray_);
  }
}
