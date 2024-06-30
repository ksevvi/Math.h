#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int x_sign = 0;
  if (y == 0 || isNAN(y)) {
    x = S21_NAN;
  } else if (isINF(x) || isNINF(x)) {
    x = S21_NAN;
  } else {
    if (x != s21_fabs(x)) {
      x_sign = 1;
      x = s21_fabs(x);
    }
    y = s21_fabs(y);
    while (x >= y) {
      x -= y;
    }
  }
  if (x_sign == 1) {
    x = -x;
  }
  return x;
}
