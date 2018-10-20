#include <stdio.h>
void uppercase(char *);
int main() {
    char s[] = "hello world";
    uppercase(s);
    printf("%s\n", s); //出力は"HELLO WORLD"
    return 0;
}
void uppercase(char *s) {
    int i = 0;
    while (*(s+i) != '\0') {
        if ('a' < *(s+i) && *(s+i) < 'z') {
            *(s+i) = *(s+i) - 0x20;
        }
        i++;
    }
}