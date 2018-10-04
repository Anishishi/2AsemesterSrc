#include <stdio.h>
#include <string.h>
int check_kaibun(char str[]);
int main(void){
  char str[] = "kayak";
  if(check_kaibun(str) == 1){
    printf("%s is palindrome.\n", str);
  }else{
    printf("%s is NOT palindrome.\n", str);
  }
  return 0;
}
int check_kaibun(char str[]){
    int i;
    int j = 1;
    int len = strlen(str);
    for (i = 0; i <= len/2 ; i++) {
        if (str[i] != str[len - i -1]){
            j = 0;
            break;
        }
    }
    return j;
}