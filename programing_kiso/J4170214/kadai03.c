#include <stdio.h>
int main() {
    int x;
    int y;
    int z;
    for (x=1; x<1000; x++) {
        for (y=x; y<1000; y++) {
            for (z=y; z<1000; z++) {
                if (x * x + y * y == z * z) {
                    printf("(%d, %d, %d\n)", x, y, z);
                }
            }
        }
    }
    return 0;
}