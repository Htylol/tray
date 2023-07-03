#pragma once

enum class Platform : int {
  linux_, // linux is a marco
  windows_,
  macos_,
  other_,
};

constexpr Platform get_platform_id() {

#if defined(__linux__)
  return Platform::linux_;
#elif defined(TARGET_OS_MAC)
  return Platform::macos_;
#elif defined(_WIN32)
  return Platform::windows_;
#else
  static_assert(false, "unknow platform");
  return Platform::other_;
#endif
}
#include <string_view>
constexpr std::string_view get_platform_name() {
  switch (get_platform_id()) {
  case Platform::linux_:
    return "Linux";
  case Platform::macos_:
    return "macOS";
  case Platform::windows_:
    return "Windows";
  case Platform::other_:
    return "Other";
  }
}
