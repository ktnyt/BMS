#pragma once

#include <iostream>
#include <cstdint>

namespace bms {
  // Todo: Integer overflow/underflow checking
  class Integer {
  protected:
    int64_t int_;
  public:
    Integer() {int_ = 0;}
    Integer(const int64_t n) {int_ = n;}
    Integer(const Integer& i) {int_ = i.int_;}
    Integer operator++ () {++this->int_;return *this;}
    Integer operator-- () {--this->int_;return *this;}
    Integer operator++ (int) {++(*this);return *this;}
    Integer operator-- (int) {--(*this);return *this;}
    Integer operator+ () {this->int_ = +this->int_;return *this;}
    Integer operator- () {this->int_ = -this->int_;return *this;}
    Integer operator~ () {this->int_ = ~this->int_;return *this;}
    friend std::ostream& operator<< (std::ostream& stream, Integer i) {return (stream << i.int_);}
    bool operator== (const Integer i) {return (this->int_ == i.int_);}
    bool operator!= (const Integer i) {return (this->int_ != i.int_);}
    bool operator>  (const Integer i) {return (this->int_ >  i.int_);}
    bool operator<  (const Integer i) {return (this->int_ <  i.int_);}
    bool operator>= (const Integer i) {return (this->int_ >= i.int_);}
    bool operator<= (const Integer i) {return (this->int_ <= i.int_);}
    Integer& operator=  (const Integer& i) {this->int_ =  i.int_;return *this;}
    Integer& operator+= (const Integer& i) {this->int_ += i.int_;return *this;}
    Integer& operator-= (const Integer& i) {this->int_ -= i.int_;return *this;}
    Integer& operator*= (const Integer& i) {this->int_ *= i.int_;return *this;}
    Integer& operator/= (const Integer& i) {this->int_ /= i.int_;return *this;}
    Integer& operator%= (const Integer& i) {this->int_ %= i.int_;return *this;}
    Integer& operator&= (const Integer& i) {this->int_ &= i.int_;return *this;}
    Integer& operator|= (const Integer& i) {this->int_ |= i.int_;return *this;}
    Integer& operator^= (const Integer& i) {this->int_ ^= i.int_;return *this;}
    Integer& operator<<= (const Integer& i) {this->int_ <<= i.int_;return *this;}
    Integer& operator>>= (const Integer& i) {this->int_ >>= i.int_;return *this;}
    friend Integer operator+ (Integer i, const Integer j) {return i += j;}
    friend Integer operator- (Integer i, const Integer j) {return i -= j;}
    friend Integer operator* (Integer i, const Integer j) {return i *= j;}
    friend Integer operator/ (Integer i, const Integer j) {return i /= j;}
    friend Integer operator% (Integer i, const Integer j) {return i %= j;}
    friend Integer operator& (Integer i, const Integer j) {return i &= j;}
    friend Integer operator| (Integer i, const Integer j) {return i |= j;}
    friend Integer operator^ (Integer i, const Integer j) {return i ^= j;}
    friend Integer operator<< (Integer i, const Integer j) {return i <<= j;}
    friend Integer operator>> (Integer i, const Integer j) {return i >>= j;}

    bool operator== (const int64_t n) {return (this->int_ == n);}
    bool operator!= (const int64_t n) {return (this->int_ != n);}
    bool operator>  (const int64_t n) {return (this->int_ >  n);}
    bool operator<  (const int64_t n) {return (this->int_ <  n);}
    bool operator>= (const int64_t n) {return (this->int_ >= n);}
    bool operator<= (const int64_t n) {return (this->int_ <= n);}
    int64_t operator=  (const int64_t n) {return this->int_ =  n;}
    int64_t operator+= (const int64_t n) {return this->int_ + n;}
    int64_t operator-= (const int64_t n) {return this->int_ - n;}
    int64_t operator*= (const int64_t n) {return this->int_ * n;}
    int64_t operator/= (const int64_t n) {return this->int_ / n;}
    int64_t operator%= (const int64_t n) {return this->int_ % n;}
    int64_t operator&= (const int64_t n) {return this->int_ & n;}
    int64_t operator|= (const int64_t n) {return this->int_ | n;}
    int64_t operator^= (const int64_t n) {return this->int_ ^ n;}
    int64_t operator<<= (const int64_t n) {return this->int_ << n;}
    int64_t operator>>= (const int64_t n) {return this->int_ >> n;}
    friend int64_t operator+ (Integer i, const int64_t n) {return i += n;}
    friend int64_t operator- (Integer i, const int64_t n) {return i -= n;}
    friend int64_t operator* (Integer i, const int64_t n) {return i *= n;}
    friend int64_t operator/ (Integer i, const int64_t n) {return i /= n;}
    friend int64_t operator% (Integer i, const int64_t n) {return i %= n;}
    friend int64_t operator& (Integer i, const int64_t n) {return i &= n;}
    friend int64_t operator| (Integer i, const int64_t n) {return i |= n;}
    friend int64_t operator^ (Integer i, const int64_t n) {return i ^= n;}
    friend int64_t operator<< (Integer i, const int64_t n) {return i |= n;}
    friend int64_t operator>> (Integer i, const int64_t n) {return i ^= n;}
    friend int64_t operator+  (const int64_t n, Integer i) {return i += n;}
    friend int64_t operator-  (const int64_t n, Integer i) {return i -= n;}
    friend int64_t operator*  (const int64_t n, Integer i) {return i *= n;}
    friend int64_t operator/  (const int64_t n, Integer i) {return i /= n;}
    friend int64_t operator%  (const int64_t n, Integer i) {return i %= n;}
    friend int64_t operator&  (const int64_t n, Integer i) {return i &= n;}
    friend int64_t operator|  (const int64_t n, Integer i) {return i |= n;}
    friend int64_t operator^  (const int64_t n, Integer i) {return i ^= n;}
    friend int64_t operator<< (const int64_t n, Integer i) {return i |= n;}
    friend int64_t operator>> (const int64_t n, Integer i) {return i ^= n;}
  };

  // Todo: Integer overflow/underflow checking
  class UInteger {
  protected:
    uint64_t int_;
  public:
    UInteger() {int_ = 0;}
    UInteger(const uint64_t n) {int_ = n;}
    UInteger(const UInteger& i) {int_ = i.int_;}
    UInteger operator++ () {++this->int_;return *this;}
    UInteger operator-- () {--this->int_;return *this;}
    UInteger operator++ (int) {++(*this);return *this;}
    UInteger operator-- (int) {--(*this);return *this;}
    UInteger operator+ () {this->int_ = +this->int_;return *this;}
    UInteger operator- () {this->int_ = -this->int_;return *this;}
    UInteger operator~ () {this->int_ = ~this->int_;return *this;}
    friend std::ostream& operator<< (std::ostream& stream, UInteger i) {return (stream << i.int_);}
    bool operator== (const UInteger i) {return (this->int_ == i.int_);}
    bool operator!= (const UInteger i) {return (this->int_ != i.int_);}
    bool operator>  (const UInteger i) {return (this->int_ >  i.int_);}
    bool operator<  (const UInteger i) {return (this->int_ <  i.int_);}
    bool operator>= (const UInteger i) {return (this->int_ >= i.int_);}
    bool operator<= (const UInteger i) {return (this->int_ <= i.int_);}
    UInteger& operator=  (const UInteger& i) {this->int_ =  i.int_;return *this;}
    UInteger& operator+= (const UInteger& i) {this->int_ += i.int_;return *this;}
    UInteger& operator-= (const UInteger& i) {this->int_ -= i.int_;return *this;}
    UInteger& operator*= (const UInteger& i) {this->int_ *= i.int_;return *this;}
    UInteger& operator/= (const UInteger& i) {this->int_ /= i.int_;return *this;}
    UInteger& operator%= (const UInteger& i) {this->int_ %= i.int_;return *this;}
    UInteger& operator&= (const UInteger& i) {this->int_ &= i.int_;return *this;}
    UInteger& operator|= (const UInteger& i) {this->int_ |= i.int_;return *this;}
    UInteger& operator^= (const UInteger& i) {this->int_ ^= i.int_;return *this;}
    UInteger& operator<<= (const UInteger& i) {this->int_ <<= i.int_;return *this;}
    UInteger& operator>>= (const UInteger& i) {this->int_ >>= i.int_;return *this;}
    friend UInteger operator+ (UInteger i, const UInteger j) {return i += j;}
    friend UInteger operator- (UInteger i, const UInteger j) {return i -= j;}
    friend UInteger operator* (UInteger i, const UInteger j) {return i *= j;}
    friend UInteger operator/ (UInteger i, const UInteger j) {return i /= j;}
    friend UInteger operator% (UInteger i, const UInteger j) {return i %= j;}
    friend UInteger operator& (UInteger i, const UInteger j) {return i &= j;}
    friend UInteger operator| (UInteger i, const UInteger j) {return i |= j;}
    friend UInteger operator^ (UInteger i, const UInteger j) {return i ^= j;}
    friend UInteger operator<< (UInteger i, const UInteger j) {return i <<= j;}
    friend UInteger operator>> (UInteger i, const UInteger j) {return i >>= j;}

    bool operator== (const uint64_t n) {return (this->int_ == n);}
    bool operator!= (const uint64_t n) {return (this->int_ != n);}
    bool operator>  (const uint64_t n) {return (this->int_ >  n);}
    bool operator<  (const uint64_t n) {return (this->int_ <  n);}
    bool operator>= (const uint64_t n) {return (this->int_ >= n);}
    bool operator<= (const uint64_t n) {return (this->int_ <= n);}
    uint64_t operator=  (const uint64_t n) {return this->int_ =  n;}
    uint64_t operator+= (const uint64_t n) {return this->int_ + n;}
    uint64_t operator-= (const uint64_t n) {return this->int_ - n;}
    uint64_t operator*= (const uint64_t n) {return this->int_ * n;}
    uint64_t operator/= (const uint64_t n) {return this->int_ / n;}
    uint64_t operator%= (const uint64_t n) {return this->int_ % n;}
    uint64_t operator&= (const uint64_t n) {return this->int_ & n;}
    uint64_t operator|= (const uint64_t n) {return this->int_ | n;}
    uint64_t operator^= (const uint64_t n) {return this->int_ ^ n;}
    uint64_t operator<<= (const uint64_t n) {return this->int_ << n;}
    uint64_t operator>>= (const uint64_t n) {return this->int_ >> n;}
    friend uint64_t operator+ (UInteger i, const uint64_t n) {return i += n;}
    friend uint64_t operator- (UInteger i, const uint64_t n) {return i -= n;}
    friend uint64_t operator* (UInteger i, const uint64_t n) {return i *= n;}
    friend uint64_t operator/ (UInteger i, const uint64_t n) {return i /= n;}
    friend uint64_t operator% (UInteger i, const uint64_t n) {return i %= n;}
    friend uint64_t operator& (UInteger i, const uint64_t n) {return i &= n;}
    friend uint64_t operator| (UInteger i, const uint64_t n) {return i |= n;}
    friend uint64_t operator^ (UInteger i, const uint64_t n) {return i ^= n;}
    friend uint64_t operator<< (UInteger i, const uint64_t n) {return i |= n;}
    friend uint64_t operator>> (UInteger i, const uint64_t n) {return i ^= n;}
    friend uint64_t operator+  (const uint64_t n, UInteger i) {return i += n;}
    friend uint64_t operator-  (const uint64_t n, UInteger i) {return i -= n;}
    friend uint64_t operator*  (const uint64_t n, UInteger i) {return i *= n;}
    friend uint64_t operator/  (const uint64_t n, UInteger i) {return i /= n;}
    friend uint64_t operator%  (const uint64_t n, UInteger i) {return i %= n;}
    friend uint64_t operator&  (const uint64_t n, UInteger i) {return i &= n;}
    friend uint64_t operator|  (const uint64_t n, UInteger i) {return i |= n;}
    friend uint64_t operator^  (const uint64_t n, UInteger i) {return i ^= n;}
    friend uint64_t operator<< (const uint64_t n, UInteger i) {return i |= n;}
    friend uint64_t operator>> (const uint64_t n, UInteger i) {return i ^= n;}
  };

  class Frame : public UInteger {
  public:
    Frame() : UInteger() { }
    Frame(uint64_t n) : UInteger(n) { }
  };

  class FPS : public UInteger {
  public:
    FPS() : UInteger() { }
    FPS(uint64_t n) : UInteger(n) { }
  };
}
