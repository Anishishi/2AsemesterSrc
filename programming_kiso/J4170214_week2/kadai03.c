#include <stdio.h>
int main() {
    int i, j, k;
    printf("2 is prime");
    for (i = 3; i <=1000; i++) {
        k = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                k = 0;
                break;
            }
        }
        if (k == 1) {
            printf("%d is prime\n", i);
        }
    }
    return 0;
}