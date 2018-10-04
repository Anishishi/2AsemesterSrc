#include <stdio.h>
int main() {
    int c;
    c = getchar();
    while( c != EOF) {
        putchar( c );
        c = getchar();
    }
}
// control + d で文字入力中止