#include "fn.h"
#include <math.h>

double get_function_value(double x) {
    if (x < 0.0) {
        return exp(-x);
    } else if (x >= 0.0 && x <= 3.0) {
        return 0.0;
    } else {
        return sin(x);
    }
}

double integral(MathFunc func, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));

    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }

    return sum * h;
}
