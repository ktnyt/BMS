#include "BMS/Scene.hpp"

namespace bms {
  Scene::Scene(FPS fps_) : FPSManager(fps_) {
    running = false;
  }

  void Scene::pollEvent() {
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0) {
      this->event(e);
    }
  }

  bool Scene::run() {
    if(running) {
      return running;
    }

    if(!this->init()) {
      std::cerr << "! Error in initializing scene" << std::endl;
      return false;
    }

    this->reset();

    running = true;

    while(running) {
      this->pollFrame();
      this->pollEvent();
    }

    return true;
  }

  void Scene::stop() {
    if(running) {
      running = false;
      this->quit();
    }
  }

  void Scene::update() {
    this->stop();
  }
}
