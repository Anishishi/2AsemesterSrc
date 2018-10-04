#include <stdio.h>
int is_prime(int);
int main() {
    int i, j;
    for (i = 4; i <= 1000; i += 2) {
        for (j = 2; j <= i/2; j++) {
            if (is_prime(j) == 1 && is_prime(i-j) == 1) {
                printf("%d = %d + %d\n", i, j, i-j);
            }
        }
    }
}
//素数なら1を返し、その他は0を返す
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