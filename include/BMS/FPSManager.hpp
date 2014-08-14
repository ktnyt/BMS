#pragma once

#include "Types.hpp"
#include "Subject.hpp"

#include <chrono>
#include <cstdint>

namespace bms {
  class FPSManager {
  protected:
    FPS fps;
    Frame frame;
    std::chrono::steady_clock::time_point prev;
    std::chrono::steady_clock::time_point curr;
  public:
    FPSManager();
    FPSManager(FPS fps_);
    Frame milliToFrame(uint64_t time);
    Frame microToFrame(uint64_t time);
    Frame nanoToFrame(uint64_t time);
    void pollFrame();
    void reset();
    virtual void update()=0;
  };
}
