#include <stdio.h>
int main() {
    int i;
    for (i = 1; i <=1000; i++) {
        if (i % 3 == 0) {
            printf("%d!!!\n", i);
        } else if (i % 10 == 3) {
            printf("%d!!!\n", i);
        } else if (30 <= i % 100 && i % 100 < 40) {
            printf("%d!!!\n", i);
        } else if (300 <= i % 1000 && i % 1000 < 400) {
            printf("%d!!!\n", i);
        } else {
            printf("%d\n", i);
        }
    }
    return 0;
}