#pragma once

typedef double (*MathFunc)(double);

double get_function_value(double x);

double integral(MathFunc func, double a, double b, int n);
