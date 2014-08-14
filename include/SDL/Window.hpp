#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <string>

namespace sdl {
  class Window {
  private:
    SDL_Window *window;
  public:
    Window();
    bool open(std::string title);
    void close();
  };
}
