#pragma once

#include "SDL.hpp"
#include "BMS/Scene.hpp"

#include <iostream>

namespace bms {
  class Play : public Scene {
  protected:
    sdl::Window window;
  public:
    Play(FPS fps_, sdl::Window window_);
    bool init();
    void quit();
    void event(SDL_Event e);
    void update();
  };
}
