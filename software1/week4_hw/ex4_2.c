#include <stdio.h>
#include <stdlib.h>
int main() {
    int *p;
    p = (int *) malloc(sizeof(int) * 1);
    *p = 100;
    printf("*p = %d\n", *p); //ポインタpで示されたアドレスに格納される整数
    printf("p = %p\n", p); //ポインタpで示されたアドレス
    printf("&p = %p\n", &p); //ポインタpが格納されているアドレス
    free(p);
    return 0;
}