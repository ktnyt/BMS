#pragma once
#include <list>
#pragma warning(disable:4224)
#pragma warning(disable:4100)
#include <functional>

namespace bms {
  template<typename F>
  class MultiFunction : public std::function<F> {
  public:
    typedef std::list<typename std::function<F>::result_type> result_type;
    //typedef typename std::function<F>::allocator_type         allocator_type;
    typedef typename std::list<std::function<F> >::const_iterator my_iterator;
    explicit MultiFunction() { }
    template<typename F2>
    MultiFunction(std::function<F2> f) {l_.push_back(f);}
    void add    (std::function<F> f) {l_.push_back(f);}
    void remove (std::function<F> f) {}
    void operator+=(std::function<F> f) {add(f);}
    void operator-=(std::function<F> f) {remove(f);}
    void clear() {l_.clear();}
    bool empty() const {return l_.empty();}
    operator bool() const {return l_.empty();}
    void operator()() const {
      for(my_iterator i = l_.begin(); i != l_.end(); ++i) {
        (*i)();
      }
    }
    template<typename T1>
    void operator()(T1 t1) const {
      for(my_iterator i = l_.begin(); i != l_.end(); ++i) {
        (*i)(t1);
      }
    }
    template<typename T1, typename T2>
    void operator()(T1 t1, T2 t2) const {
      for(my_iterator i = l_.begin(); i != l_.end(); ++i) {
        (*i)(t1, t2);
      }
    }
    template<typename T1, typename T2, typename T3>
    void operator()(T1 t1, T2 t2, T3 t3) const {
      for(my_iterator i = l_.begin(); i != l_.end(); ++i) {
        (*i)(t1, t2, t3);
      }
    }
  private:
    std::list<std::function<F> > l_;
  };

  template<typename MF1, typename MF2>
  void swap(MultiFunction<MF1>& mf1, MultiFunction<MF2>& mf2) {
    mf1.swap(mf2);
  }

  template<typename MF1, typename MF2>
  bool operator==(const MultiFunction<MF1>& mf1, const MultiFunction<MF2>& mf2) {
    return false;
  }

  template<typename MF1, typename MF2>
  bool operator!=(const MultiFunction<MF1>& mf1, const MultiFunction<MF2>& mf2) {
    return !(mf1 == mf2);
  }
}
