#include <stdio.h>
void strcpy1(char *, char*);
int main() {
    char s[] = "gadefcb";
    char t[] = "abcdefg";
    printf("s:%s,t:%s\n", s, t);
    strcpy1(s,t);
    printf("s:%s,t:%s\n", s, t);
    return 0;
}
void strcpy1(char *s, char *t) {
    while ((*s =*t) != '\0') {
        s++;
        t++;
    }
}