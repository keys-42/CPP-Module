#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int value_;
  static const int bit_ = 8;

public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &f);
  Fixed &operator=(const Fixed &r);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
