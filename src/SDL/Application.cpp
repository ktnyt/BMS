#include "SDL/Application.hpp"

namespace sdl {
  Application::Application() {
    initialized = false;
  }

  bool Application::initAll() {
    std::cerr << "Initializing all SDL components" << std::endl;
    return (initialized = (this->initSDL() && this->initIMG() && this->initMIX()));
  }

  bool Application::initSDL() {
    if(initialized) {
      return true;
    }

    std::cerr << "- Initializing SDL" << std::endl;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
      std::cerr << "! Failed to initialize SDL" << std::endl;
      std::cerr << "! SDL Error: " << SDL_GetError() << std::endl;
      return false;
    }

    return true;
  }

  bool Application::initIMG() {
    if(initialized) {
      return true;
    }

    std::cerr << "- Initializing SDL_image" << std::endl;
    int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if(!(IMG_Init(flags) & flags)) {
      std::cerr << "! Failed to initialize SDL_Image" << std::endl;
      std::cerr << "! SDL_image Error: " << IMG_GetError() << std::endl;
      return false;
    }

    return true;
  }

  bool Application::initMIX() {
    if(initialized) {
      return true;
    }

    std::cerr << "- Initializing SDL_mixer" << std::endl;
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
      std::cerr << "! Failed to open audio" << std::endl;
      std::cerr << "! SDL_mixer Error: " << Mix_GetError() << std::endl;
      return false;
    }

    Mix_AllocateChannels(32);
    return true;
  }

  void Application::quitAll() {
    if(initialized) {
      std::cerr << "Quitting all SDL components" << std::endl;
      this->quitMIX();
      this->quitIMG();
      this->quitSDL();
    }
  }

  void Application::quitSDL() {
    if(initialized) {
      std::cerr << "- Quitting SDL" << std::endl;
      SDL_Quit();
    }
  }

  void Application::quitIMG() {
    if(initialized) {
      std::cerr << "- Quitting SDL_image" << std::endl;
      IMG_Quit();
    }
  }

  void Application::quitMIX() {
    if(initialized) {
      std::cerr << "- Quitting SDL_mixer" << std::endl;
      Mix_CloseAudio();
      Mix_Quit();
    }
  }
}
