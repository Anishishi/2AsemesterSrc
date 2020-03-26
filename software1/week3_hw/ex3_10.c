#include <stdio.h>
#include <math.h>
#define NALPHA 26 //アルファベットの種類
int main() 
{ 
    double count[NALPHA][NALPHA]; 
    double prob[NALPHA][NALPHA], re_p[NALPHA][NALPHA];
    double ent[NALPHA]; 
    int c, i, j; int first, second; 
  
    for( i = 0 ; i < NALPHA ; i++ ) { 
        for( j = 0 ; j < NALPHA ; j++ ) { 
            count[i][j] = 0; 
        } 
    } 
    second = ' '; 
  
    while( ( c = getchar() ) != EOF ) { // 現在読み込んだ文字はcに代入されている
        first = second; 
        second = c; 
        if( 'a' <= first && first <= 'z' && 'a' <= second && second <= 'z' ) { 
            count[first-'a'][second-'a']++; // アルファベットが続く場合はカウントアップ
        } 
    } 
//ここまででcount[][]ができた
    for (i=0; i<NALPHA; i++) {
        double sum=0;
        ent[i] = 0.0;
        for (j=0; j<NALPHA; j++) {
            sum += count[i][j];
        }
        for (j=0; j<NALPHA; j++) {
            prob[i][j] = (double)count[i][j] / (double)sum;
            if (prob[i][j] != 0) {
                double log_p =  log2(prob[i][j]);
                re_p[i][j] = prob[i][j] * (- log_p);
            } else { 
                re_p[i][j] = 0.0;
            }
        }
        for (j=0; j<NALPHA; j++) {
            ent[i] += re_p[i][j];
        }
        printf("[%c]: ent = %e\n", 'a' + i, ent[i]);
    }
    return 0;
}