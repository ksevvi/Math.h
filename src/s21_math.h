#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define S21_PI 3.14159265358979324
#define S21_PI_2 1.57079632679489661923
#define S21_EPS 1e-17
#define S21_MAX 1e17
#define S21_EXP 2.71828182845904523536028747135266250
#define S21_INF 1.0 / 0.0
#define S21_NINF -1.0 / 0.0
#define S21_NAN (__builtin_nanf("0x7fc00000"))  // float
#define isNAN(x) (x != x)
#define isINT(x) (x == (int)x)
#define isINF(x) (x == S21_INF)
#define isNINF(x) (x == S21_NINF)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_