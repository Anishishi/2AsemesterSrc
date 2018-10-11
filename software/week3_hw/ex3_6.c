#include <stdio.h> 
#define NALPHA 26 //アルファベットの種類
int main() 
{ 
    int count[NALPHA]; 
    int c, i; 
    for( i = 0 ; i < NALPHA ; ++i ) { //カウント結果を記録する配列を初期化する
        count[i] = 0; 
    } 
  
    while( ( c = getchar() ) != EOF ) { 
        if( 'a' <= c && c <= 'z' ) {
            count[c-'a']++;
        } 
    } 
  
    for( i = 0 ; i < NALPHA ; i++ ) { 
        printf( "%c : %d\n", 'a'+i, count[i] );  
    } 
  
    return 0;
}