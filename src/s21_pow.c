#include "s21_math.h"

long double checking_for_exceptions(double base, double exp) {
  double result = -2.0;
  if (base == 0.0) {
    if (isNAN(exp)) {
      result = S21_NAN;
    } else if (exp == -S21_NAN) {
      result = -S21_NAN;
    } else if (isNINF(exp)) {
      result = S21_INF;
    } else if (exp == 0.0) {
      result = 1.0;
    } else if (exp < 0) {
      result = S21_INF;
    }
  } else if (base == 1.0) {
    result = 1.0;
  } else if (base == -1.0) {
    if (isINF(exp) || isNINF(exp)) {
      result = 1.0;
    }
  } else if (base == (__builtin_nanf(""))) {
    result = S21_NAN;
  } else if (isINT(base)) {
    if (isINF(exp)) {
      result = S21_INF;
    } else if (isNINF(exp)) {
      result = 0.0;
    }
  } else if (isINF(base)) {
    if (exp == 0.0) {
      result = 1.0;
    } else if (exp > 0 && isINT(exp)) {
      result = S21_INF;
    } else if (isINF(exp)) {
      result = S21_INF;
    } else if (isNAN(exp)) {
      result = S21_NAN;
    }
  } else if (isNINF(base)) {
    if (exp == 0.0) {
      result = 1.0;
    } else if (exp > 0 && isINT(exp)) {
      result = S21_NINF;
    } else if (isINF(exp)) {
      result = S21_INF;
    } else if (isNAN(exp)) {
      result = S21_NAN;
    } else if (exp > 0) {
      result = S21_NAN;
    } else if (isNINF(exp)) {
      result = 0;
    }
  }

  return result;
}

long double fast_pow(double base, long long int exp) {
  long double result = 1.0;
  long long abs_exp = s21_abs(exp);
  while (abs_exp) {
    result *= base;
    abs_exp--;
  }
  return (exp < 0) ? 1.0 / result : result;
}

long double s21_pow(double base, double exp) {
  long double result = checking_for_exceptions(base, exp);
  if (result == -2.0) {
    if (isINT(exp)) {
      result = fast_pow(base, exp);
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}
