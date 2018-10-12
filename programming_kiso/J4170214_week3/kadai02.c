#include <stdio.h>
double sqrt_cf(double);
double k(double, int);
int main() {
    double z = 2;
    double s = sqrt_cf(z);
    printf("√%f = %f\n", z, s);
    return 0;
}
double sqrt_cf(double z) {
    return 1.0 + k(z, 0);
}
double k(double z, int depth) {
    if ( depth == 10) {
        return 0;
    } else {
        return (z - 1.0) / ( 2.0 + k(z, depth + 1));
    }
}