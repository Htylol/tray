#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "tray_raw.h"
namespace trays {
class Menu {
public:
  std::string text_;
  bool check_able_{};
  bool disabled_{};
  std::function<void(Menu* self)> on_click_;
};
class Tray {
public:
  Tray(std::string icon_path, std::vector<Menu> menus = {});
  void run();

  void add(Menu menu);

private:
  std::vector<std::unique_ptr<Menu>> menus_;
  std::vector<tray_menu> raw_menus_;
  std::string icon_;
  struct tray tray_ {};
  bool init_finished_{};
};
} // namespace trays