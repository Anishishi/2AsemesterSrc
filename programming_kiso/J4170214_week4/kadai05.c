#include <stdio.h>
int char_num(char);
int roman2num(char *);
int main() {
    //Examples
    printf("XI = %d\n", roman2num("XI")); //11
    printf("XII = %d\n", roman2num("XII")); //12
    printf("XIV = %d\n", roman2num("XIV")); //14
    printf("XVIII = %d\n", roman2num("XVIII")); //18
    printf("XXIV = %d\n", roman2num("XXIV")); //24
    printf("XLIII = %d\n", roman2num("XLIII")); //43
    printf("XCIX = %d\n", roman2num("XCIX")); //99
    printf("CDXCV = %d\n", roman2num("CDXCV")); //495
    printf("MDCCCLXXXVIII = %d\n", roman2num("MDCCCLXXXVIII")); //1888
    printf("MCMXLV = %d\n", roman2num("MCMXLV")); //1945
    printf("MMMCMXCIV = %d\n", roman2num("MMMCMXCIX")); //3999
    return 0;
}
int char_num(char c) {
    if (c == 'I') {
        return 1;
    } else if (c == 'V') {
        return 5;
    } else if (c == 'X') {
        return 10;
    } else if (c == 'L') {
        return 50;
    } else if (c == 'C') {
        return 100;
    } else if (c == 'D') {
        return 500;
    } else if (c == 'M') {
        return 1000;
    } else {
        return 0;
    }
}
int roman2num(char *s) {
    int i=0;
    int ans=0;
    if (*s == '\0') {
        return 0;
    } else {
        if (*(s+1) == '\0') {
            ans=char_num(*s);
            return ans;
        } else {
            while (*(s+i+1) != '\0') {
                int x=char_num(*(s+i)), y=char_num(*(s+i+1));
                if (x>=y) {
                    ans=ans+x;
                } else {
                    ans=ans-x;
                }
                i++;
            }
            ans=ans+char_num(*(s+i));
            return ans;
        }
    }
    return ans;
}