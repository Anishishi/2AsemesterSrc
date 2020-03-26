#include <stdio.h>

int main()
{
    int a, b, c;
    char buf[1024];
    int cnt = 0;
    while (fgets(buf, sizeof(buf), stdin)) {
        sscanf(buf, "%d,%d,%d", &a, &b, &c);
        if (a * a + b * b == c * c) {
            cnt++;
            printf("%d, %d, %d\n", a, b, c);
            continue;
        }
        if (b * b + c * c == a * a) {
            cnt++;
            printf("%d, %d, %d\n", a, b, c);
            continue;
        }
        if (c * c + a * a == b * b) {
            cnt++;
            printf("%d, %d, %d\n", a, b, c);
            continue;
        }
    }

    printf("直角三角形は%d個\n", cnt);
}