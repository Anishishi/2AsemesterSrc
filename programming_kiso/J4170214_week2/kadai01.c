#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d, e, sum, x, ans;
    int n;
    for (n = 1; n < 100; n++) {
        a = pow (2, n-1);
        b = n * n * a;
        c = 1.0/b;
        sum = sum + c;
    }
    d = log(2);
    e = d * d;
    x = (sum + e) * 6;
    ans = sqrt(x);
    printf("π = %f\n", ans);
    return 0;
}