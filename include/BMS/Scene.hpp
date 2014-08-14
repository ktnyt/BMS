#pragma once

#include "SDL.hpp"
#include "BMS/FPSManager.hpp"

#include <iostream>

namespace bms {
  class Scene : public FPSManager {
  protected:
    bool running;
  public:
    Scene(FPS fps_);
    void pollEvent();
    virtual bool run();
    virtual void stop();
    virtual void update();
    virtual bool init()=0;
    virtual void quit()=0;
    virtual void event(SDL_Event e)=0;
  };
}
