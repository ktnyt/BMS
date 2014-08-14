#include "ReBMS.hpp"

namespace game {
  ReBMS::ReBMS(uint64_t fps_) {
    fps = fps_ & 0xff;
    window = sdl::Window();
  }

  bool ReBMS::init() {
    return this->initAll() && window.open("RevolutionBMS");
  }

  int ReBMS::run() {
    if(!this->init()) {
      return -1;
    }

    bms::Play play = bms::Play(fps, window);

    if(!play.run()) {
      std::cerr << "! Error: Failed to run scene" << std::endl;
    }

    quit();

    return 0;
  }

  void ReBMS::quit() {
    this->quitAll();
  }
}
