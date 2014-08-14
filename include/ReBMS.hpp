#pragma once

#include <iostream>
#include "BMS.hpp"

namespace game {
  class ReBMS : public sdl::Application {
  private:
    bms::FPS fps;
    sdl::Window window;
  public:
    ReBMS(uint64_t);
    bool init();
    int run();
    void quit();
  };
}
