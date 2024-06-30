#include "s21_math.h"

long double s21_acos(double x) {
  long double res;
  if (x > 1.0 || x < -1.0 || x != x) {
    res = S21_NAN;
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = S21_PI;
  } else {
    res = S21_PI_2 - s21_asin(x);
  }
  return res;
}