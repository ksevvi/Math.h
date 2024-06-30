#include "s21_math.h"

long double s21_log(double x) {
  int exponent = 0;
  long double result = 0;
  long double approximation = 0;

  if (x != x) {
    result = x;
  } else if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    result = 0 / 0.;
  } else {
    if (x < 0) {
      result = 0 / 0.0;
    } else if (x != 0) {
      for (; x >= S21_EXP; x /= S21_EXP, exponent++) continue;

      for (int i = 0; i < 100; i++) {
        approximation = result;
        result = approximation + 2 * (x - s21_exp(approximation)) /
                                     (x + s21_exp(approximation));
      }
    } else {
      result = -1.0 / 0.0;
    }
  }
  return (result + exponent);
}
