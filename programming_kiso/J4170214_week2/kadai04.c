#include <stdio.h>
#include <math.h>
int is_prime(int);
int main() {
    int a, b;
    double cross;
    cross = 1 - (1.0 / (2 * 2));
    for (a = 3; a <= 10000; a++) {
        b = is_prime(a);
        if (b == 1) {
            cross = cross * (1 - 1.0 / (a * a));
        }
    }
    double ans = sqrt(6.0 / cross);
    printf("pi = %f\n", ans);
    return 0;
    
}
int is_prime(n) {
    int i, k = 1;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            k = 0;
            break;
        }
    }
    return k;
}