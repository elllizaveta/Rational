#include "rational.h"
#include <numeric>

void Rational::Fix() {
  int32_t delit_budem = std::gcd(numerator_, denominator_);
  numerator_ = numerator_ / delit_budem;
  denominator_ = denominator_ / delit_budem;
  if (denominator_ < 0) {
    denominator_ *= -1;
    numerator_ *= -1;
  }
}

Rational::Rational() : numerator_(0), denominator_(1) {
}

Rational::Rational(int32_t z) : numerator_(z), denominator_(1) {
}

Rational::Rational(int32_t numerator, int32_t denominator) : numerator_(numerator), denominator_(denominator) {
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  Fix();
}

const int32_t& Rational::GetNumerator() const {
  return numerator_;
}

const int32_t& Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int32_t numerator) {
  numerator_ = numerator;
  Fix();
}

void Rational::SetDenominator(int32_t denominator) {
  if (denominator == 0) {
    throw RationalDivisionByZero{};
  }
  denominator_ = denominator;
  Fix();
}

Rational operator*(const Rational& first, const Rational& second) {
  Rational ans = first;
  return ans *= second;
}

Rational operator/(const Rational& first, const Rational& second) {
  Rational ans = first;
  return ans /= second;
}

Rational operator-(const Rational& first, const Rational& second) {
  Rational ans = first;
  return ans -= second;
}

Rational operator+(const Rational& first, const Rational& second) {
  Rational ans = first;
  return ans += second;
}

Rational& Rational::operator+=(const Rational& other) {
  numerator_ = numerator_ * other.denominator_ + denominator_ * other.numerator_;
  denominator_ = denominator_ * other.denominator_;
  Fix();
  return *this;
}

Rational& Rational::operator-=(const Rational& other) {
  numerator_ = numerator_ * other.denominator_ - denominator_ * other.numerator_;
  denominator_ = denominator_ * other.denominator_;
  Fix();
  return *this;
}

Rational& Rational::operator*=(const Rational& other) {
  numerator_ = numerator_ * other.numerator_;
  denominator_ = denominator_ * other.denominator_;
  Fix();
  return *this;
}

Rational& Rational::operator/=(const Rational& other) {
  if (other.numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  numerator_ = numerator_ * other.denominator_;
  denominator_ = denominator_ * other.numerator_;
  Fix();
  return *this;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  Rational copy = *this;
  copy.numerator_ *= -1;
  return copy;
}

Rational& Rational::operator++() {
  numerator_ += denominator_;
  return *this;
}

Rational& Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int) {
  Rational copy = *this;
  numerator_ -= denominator_;
  return copy;
}

Rational Rational::operator++(int) {
  Rational copy = *this;
  numerator_ += denominator_;
  return copy;
}

bool Rational::operator<(const Rational& other) const {
  return this->numerator_ * other.GetDenominator() < other.GetNumerator() * this->denominator_;
}

bool operator>(const Rational& first, const Rational& second) {
  return second < first;
}

bool operator>=(const Rational& first, const Rational& second) {
  return !(first < second);
}

bool operator<=(const Rational& first, const Rational& second) {
  return !(second < first);
}

bool operator==(const Rational& first, const Rational& second) {
  return !(first < second) && !(second < first);
}

bool operator!=(const Rational& first, const Rational& second) {
  return (first < second) || (second < first);
}

std::istream& operator>>(std::istream& in, Rational& x) {
  int32_t numerator = 0;
  int32_t denominator = 1;
  while (std::isspace(in.peek())) {
    in.get();
  }
  int32_t min = 1;
  if (in.peek() == '-') {
    in.get();
    min *= -1;
  }
  if (in.peek() == '+') {
    in.get();
  }
  while (std::isdigit(in.peek())) {
    char c = in.get();
    numerator *= 10;
    numerator += c - '0';
  }
  if (in.peek() == '/') {
    in.get();
    denominator = 0;
    if (in.peek() == '-') {
      in.get();
      min *= -1;
    }
    if (in.peek() == '+') {
      in.get();
    }
    while (std::isdigit(in.peek())) {
      char c = in.get();
      denominator *= 10;
      denominator += c - '0';
    }
  }
  numerator *= min;
  x = Rational(numerator, denominator);
  x.Fix();
  return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& x) {
  if (x.denominator_ == 1) {
    out << x.numerator_;
    return out;
  }
  out << x.numerator_ << '/' << x.denominator_;
  return out;
}
