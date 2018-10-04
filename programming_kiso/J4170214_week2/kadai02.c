#include <stdio.h>
#include <math.h>
int zeller (int, int, int);
int main() {
    int w, year, month, day;
    year = 2018, month = 10, day = 3;
    w = zeller (year, month, day);
    printf("%d/%d/%d is ", year, month, day);
    switch (w) {
        case 0: printf("Sat.\n"); break;
        case 1: printf("Sun.\n"); break;
        case 2: printf("Mon.\n"); break;
        case 3: printf("Tue.\n"); break;
        case 4: printf("Wed.\n"); break;
        case 5: printf("Thurs.\n"); break;
        case 6: printf("Fri.\n"); break;        
    }
    return 0;
}
int zeller (int y, int m, int d) {
    double a = y /100;
    int h = (int) a;
    int ye = y - (h * 100);
    int w = ye + (ye/4) + (h/4) - 2*h + (13*(m+1)/5) + d;
    return w%7;
}