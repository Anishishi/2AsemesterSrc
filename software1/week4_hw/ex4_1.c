#include <stdlib.h>
#include <stdio.h>
int main() {
    int *i, *sum; // int *i, *sum;
    i = (int*)malloc(sizeof(int) * 1);
    sum = (int*)malloc(sizeof(int) * 1);
    for (*i=0; *i<=10; (*i)++) {
        *sum = *sum + *i;
    }
    printf("sum = %d\n", *sum);
    return 0;
}