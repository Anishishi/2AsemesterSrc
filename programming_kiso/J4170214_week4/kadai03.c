#include <stdio.h>
void reverse(char *);
int main() {
    char s[] = "hello";
    reverse(s);
    printf("hello→%s\n", s); //出力は"olleh"
    return 0;
}
void reverse(char *s) {
    int i = 0;
    int len = 0;
    while (*(s+i) != '\0') {
        i++;
        len++;
    }
    for (int j=0; j<(len/2); j++) {
        char x=*(s+j);
        char y=*(s+len-j-1);
        *(s+j)=y;
        *(s+len-j-1)=x;
    }
}