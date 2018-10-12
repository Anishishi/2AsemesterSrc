#include <stdio.h>
#include <math.h>
double f(double);
double dfdx(double);
double newton(double);

int main() {
    double x0 = 1.0;
    double solution = newton(x0);
    printf("solution is %f\n", solution);
    return 0;
}
double f(double x) {
    return exp( x ) + x;
}
double dfdx(double x) {
    return exp( x ) + 1;
}
double newton(double x) {
    double y = (0.0 - f(x) / dfdx(x)) + x;
    if ( fabs(y - x) < 0.00000001) {
        return x;
    } else {
        return newton(y);
    }
}