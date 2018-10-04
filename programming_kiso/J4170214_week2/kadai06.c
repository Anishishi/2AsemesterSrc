#include <stdio.h>
int main() {
    int x;
    int y;
    int z;
    int i;
    for (x=1; x<1000; x++) {
        for (y=x; y<1000; y++) {
            for (z=y; z<1000; z++) {
                if (x * x + y * y == z * z) {
                    int d = 1;
                    for (i = 2; i <= 1000; i++){
                        int a = x % i;
                        int b = y % i;
                        int c = z % i;
                        if (a == 0 && b == 0 && c == 0) {
                            d = 0;
                            break;
                        }
                    }
                    if ( d == 1) {
                        printf("(%d, %d, %d)\n", x, y, z);
                    }
                }
            }
        }
    }
    return 0;
}