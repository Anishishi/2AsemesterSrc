#include <stdio.h> 
#define NALPHA 26 
int main() 
{ 
    int count[NALPHA][NALPHA]; 
    int c, i, j; 
    int first, second; 
  
    for( i = 0 ; i < NALPHA ; i++ ) { 
        for( j = 0 ; j < NALPHA ; j++ ) { 
            count[i][j] = 0; 
        } 
    } 
    second = ' '; 
    while( ( c = getchar() ) != EOF ) { 
        first = second;/*最初の文字をセット*/
        second = c;/*次に来る文字をセット*/ 
        if( 'a' <= first && first <= 'z' && 'a' <= second && second <= 'z') { 
            count[first-'a'][second-'a']++; 
        } 
    }
  
  // 表示
    for( i = 0 ; i < NALPHA ; i++ ) { 
        for( j = 0 ; j < NALPHA ; j++ ) { 
            printf ("[%c][%c] = %d\n", 'a'+i, 'a'+j, count[i][j] ); 
        } 
    } 
    return 0;
}