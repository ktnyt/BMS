#include "BMS/FPSManager.hpp"

namespace bms {
  FPSManager::FPSManager() {
    fps = 29 & 0xff;
    frame = Frame();
    prev = std::chrono::steady_clock::now();
  }

  FPSManager::FPSManager(FPS fps_) {
    fps = fps_ & 0xff;
    frame = Frame();
    prev = std::chrono::steady_clock::now();
  }

  Frame FPSManager::milliToFrame(uint64_t time) {
    return Frame((time * fps) / 1000);
  }

  Frame FPSManager::microToFrame(uint64_t time) {
    return Frame((time * fps) / 1000000);
  }

  Frame FPSManager::nanoToFrame(uint64_t time) {
    return Frame((time * fps) / 1000000000);
  }

  void FPSManager::pollFrame() {
    curr = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = (curr - prev);
    Frame now = nanoToFrame(duration.count());
    if(now > frame) {
      while(now > frame) frame++;
      this->update();
    }
  }

  void FPSManager::reset() {
    frame = 0;
  }
}
