#include <stdio.h>

int strlen1(char *);
int main() {
    char ch[] = "abcdefg";
    printf("文字列:%sの長さは%dです。\n", ch, strlen1(ch));
    return 0;
}
int strlen1(char *s) {
    int n;
    for(n=0; *s != '\0'; s++) {
        n++;
    }
    return n;
}