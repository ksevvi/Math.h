#include "s21_math.h"

long double double_factorial(long x) {
  long double fact = 1;
  if (x % 2 == 0) {
    for (int i = 2; i <= x; i += 2) {
      fact *= i;
    }
  } else {
    for (int i = 1; i <= x; i += 2) {
      fact *= i;
    }
  }
  return fact;
}
long double s21_asin(double x) {
  long double result = x;
  if (x > 1.0 || x < -1.0 || x != x) {
    result = S21_NAN;
  } else if (x == 1) {
    result = S21_PI_2;
  } else if (x == -1) {
    result = -S21_PI_2;
  } else {
    int i = 1;
    while (i < 100000) {
      long double fact = (double_factorial(2 * i - 1) * s21_pow(x, 2 * i + 1)) /
                         (double_factorial(2 * i) * (2 * i + 1));
      if (fact < 0.0000000000001L && fact > -0.0000000000001L) {
        break;
      }
      result += fact;
      i++;
    }
  }
  return result;
}
