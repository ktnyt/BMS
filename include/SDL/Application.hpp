#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>

namespace sdl {
  class Application {
  private:
    bool initialized;
  protected:
    bool initAll();
    bool initSDL();
    bool initIMG();
    bool initMIX();
    void quitAll();
    void quitSDL();
    void quitIMG();
    void quitMIX();
  public:
    Application();
    virtual bool init()=0;
    virtual int run()=0;
    virtual void quit()=0;
  };
}

