#include <stdio.h>
int main() {
    int n = 158340421;
    int i;
    for (i = 1; i < 1000; i++) {
        if (i * i * i == n) {
            printf("%d\n", i);
        }
    }
    return 0;
}