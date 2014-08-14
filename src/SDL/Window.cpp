#include "SDL/Window.hpp"

namespace sdl {
  Window::Window() {
    window = NULL;
  }

  bool Window::open(std::string title) {
    if(window != NULL) {
      this->close();
    }

    if((window = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  640, 480, SDL_WINDOW_SHOWN)) == NULL) {
      std::cerr << "Failed to open window" << std::endl;
      return false;
    }

    return true;
  }

  void Window::close() {
    SDL_DestroyWindow(window);
    window = NULL;
  }
}
