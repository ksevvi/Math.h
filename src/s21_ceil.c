#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (isNAN(x)) {
    result = S21_NAN;
  } else if (isINF(x)) {
    result = S21_INF;
  } else if (isNINF(x)) {
    result = S21_NINF;
  } else if (x > 0 && x != result) {
    result += 1;
  }
  return result;
}