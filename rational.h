#ifndef NU_POGNALI
#define NU_POGNALI
#include <iostream>
#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

struct Rational {
 private:
  int32_t numerator_;
  int32_t denominator_;
  void Fix();

  friend std::istream& operator>>(std::istream& in, Rational& x);
  friend std::ostream& operator<<(std::ostream& out, const Rational& x);

 public:
  Rational();
  Rational(int32_t z);  // NOLINT
  Rational(int32_t numerator, int32_t denominator);
  const int32_t& GetNumerator() const;
  const int32_t& GetDenominator() const;
  void SetNumerator(int32_t);
  void SetDenominator(int32_t);
  Rational& operator+=(const Rational& other);
  Rational& operator-=(const Rational& other);
  Rational& operator*=(const Rational& other);
  Rational& operator/=(const Rational& other);
  Rational operator+() const;
  Rational operator-() const;
  Rational& operator++();
  Rational& operator--();
  Rational operator++(int);
  Rational operator--(int);
  bool operator<(const Rational& other) const;
};

Rational operator+(const Rational& first, const Rational& second);
Rational operator-(const Rational& first, const Rational& second);
Rational operator*(const Rational& first, const Rational& second);
Rational operator/(const Rational& first, const Rational& second);
bool operator>(const Rational& first, const Rational& second);
bool operator>=(const Rational& first, const Rational& second);
bool operator<=(const Rational& first, const Rational& second);
bool operator==(const Rational& first, const Rational& second);
bool operator!=(const Rational& first, const Rational& second);
std::ostream& operator<<(std::ostream& out, const Rational& x);
std::istream& operator>>(std::istream& in, Rational& x);

#endif