#include <stdio.h>
#include <math.h>
int mod_apm(int, int, int);
int main() {
    int ans, a=541, p=1234, m=1299709;
    ans = mod_apm(a, p, m);
    printf(" %d^%d mod %d = %d\n", a, p, m, ans);
    return 0;
}
int mod_apm(int a, int p, int m) {
    if ( p <= 5 && pow(a, p) < m) {
        return pow(a, p);
    } else {
        return a * mod_apm(a, p-1, m) % m;
    }
}