#include <stdio.h>
#include <stdlib.h>
void func1(int *input);
void func2(int input);
int main(void) {
    int a=100;
    int *b;
    b=(int *)malloc(sizeof(int));
    *b=200;
    func1(&a);
    func1(b);
    func2(a);
    func2(*b);
    return 0;
}
void func1(int *input) {
    printf("%d\n", *input);
}
void func2(int input) {
    printf("%d\n", input);
}