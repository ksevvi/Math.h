#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0;
  if (isINF(x)) {
    res = S21_INF;
  } else if (isNAN(x)) {
    res = S21_NAN;
  } else if (isNINF(x)) {
    res = 0;
  } else {
    int n = 1;
    long double a = x, term = 1;
    if (x < 0.0) a = -x;
    for (int i = 0; i < 1600; i++) {
      term *= a / n++;
      res += term;
    }
    if (x < 0.0) res = 1 / res;
  }
  return res;
}
