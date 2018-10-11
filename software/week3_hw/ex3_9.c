#include <stdio.h>
#include <math.h>
#define NALPHA 26 //アルファベットの種類
int main() 
{ 
    int count[NALPHA]; 
    int c, i, sum=0; 
    double prob[NALPHA], re_p[NALPHA];
    double ent=0;
    for( i = 0 ; i < NALPHA ; ++i ) { //カウント結果を記録する配列を初期化する
        count[i] = 0; 
    }  
    while( ( c = getchar() ) != EOF ) { 
        if( 'a' <= c && c <= 'z' ) {
            count[c-'a']++;
        } 
    }
//ここまででcount[]ができた
    for (i=0; i<NALPHA; i++) {
        sum += count[i];
    }
    for (i=0; i<NALPHA; i++) {
        prob[i] = (double)count[i] / (double)sum;
        double log_p =  log2(prob[i]);
        re_p[i] = prob[i] * (- log_p);
    }
    for (i=0; i<NALPHA; i++) {
        ent += re_p[i];
    }
    printf("entropy = %e\n", ent);
    return 0;
}