#include <stdio.h>
char num2roman(int);
int main() {
    //Examples
    printf("11 = ");
    num2roman(11); //XI
    printf("12 = ");
    num2roman(12); //XII
    printf("14 = ");
    num2roman(14); //XIV
    printf("18 = ");
    num2roman(18); //XVIII
    printf("24 = ");
    num2roman(24); //XXIV
    printf("43 = ");
    num2roman(43); //XLIII
    printf("99 = ");
    num2roman(99); //XCIX
    printf("495 = ");
    num2roman(495); //CDXCV
    printf("1888 = ");
    num2roman(1888); //MDCCCLXXXVIII
    printf("1945 = ");
    num2roman(1945); //MCMXLV
    printf("3999 = ");
    num2roman(3999); //MMMCMXCIX
    return 0;
}
char num2roman(int n) {
    if (n>=4000 || n==0) {
        printf("out_of_range");
    } else {
        int a=n/1000, i;
        for (i=0; i<a; i++) {
            printf("M");
        }
        int b=(n-a*1000)/100;
        if (b==9) {
            printf("CM");
        } else if (b>=5) {
            printf("D");
            for (i=0; i<b-5; i++) {
                printf("C");
            }
        } else if (b>=1) {
            printf("C");
            if (b==2) {
                printf("C");
            } else if (b==3) {
                printf("CC");
            } else if (b==4){
                printf("D");
            }
        }
        int c=(n-a*1000-b*100)/10;
        if (c==9) {
            printf("XC");
        } else if (c==4) {
            printf("XL");
        } else if (c>=5) {
            printf("L");
            for (i=0; i<c-5; i++) {
                printf("X");
            }
        } else {
            for (i=0; i<c; i++) {
                printf("X");
            }
        }
        int d=n-a*1000-b*100-c*10;
        if (d==9) {
            printf("IX");
        } else if (d==4) {
            printf("IV");
        } else if (d>=5) {
            printf("V");
            for (i=0; i<d-5; i++) {
                printf("I");
            }
        } else {
            for (i=0; i<d; i++) {
                printf("I");
            }
        }
    }
    printf("\n");
    return 'a';
}
