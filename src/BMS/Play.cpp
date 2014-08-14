#include "BMS/Play.hpp"

namespace bms {
  Play::Play(FPS fps_, sdl::Window window_) : Scene(fps_) {
    window = window_;
  }

  bool Play::init() {
    std::cerr << "Initializing play scene" << std::endl;
    return true;
  }

  void Play::quit() {
    std::cerr << "Quitting play scene" << std::endl;
  }

  void Play::event(SDL_Event e) {
    if(e.type == SDL_QUIT) {
      this->stop();
    } else if (e.type == SDL_KEYDOWN) {
      switch(e.key.keysym.sym) {
      case SDLK_q:
      case SDLK_ESCAPE:
        this->stop();
        break;
      default:
        break;
      }
    }
  }

  void Play::update() {
    
  }
}
