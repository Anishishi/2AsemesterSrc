#include <stdio.h>
#include <math.h>
int main() {
    double pi = 3.14;
    double i;
    for (i = 5.0 * pi; i >= -5.0 * pi; i -= pi / 100.0) {
        printf("%f\t%f\n", i, sin(i * pi) / (pi * i));
    }
    return 0;
}