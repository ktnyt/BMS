#pragma once
#include "MultiFunction.hpp"

namespace bms {
  template<typename F>
  class Subject {
  protected:
    ~Subject() {}
    MultiFunction<F> notify;
  public:
    void attach(std::function<F> o) {notify += o;}
    void detach(std::function<F> o) {notify -= o;}
    void clear() {notify.clear();}
  };
}
