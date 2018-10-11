#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 5 // スロットマシンの数
#define N 1000000 // コインの数．採点時には1,000,000などの大きな数にする．
int bet(int k); //変更不可
int max(double, double, double, double, double); //期待値最大のマシーンの番号を求める
int main() { //自由に変更して良い
//この方法は試行回数が少ない時には、それぞれの期待値を満足に計算できないため、試行回数の多い時に効果を発揮すると考えられる。
    srand((unsigned) time(NULL));
    int credit = N, sum=0;
    double bottom[] = {0.0, 0.0, 0.0, 0.0, 0.0};
    double upper[] = {0.0, 0.0, 0.0, 0.0, 0.0};
    double e[] = {0.0, 0.0, 0.0, 0.0, 0.0};
    double reward=0.0;
    for (int i = 0; i <= 4; i++) { //一回当たるまでそれぞれのスロットを回し、それぞれ期待値を計算する
        while (credit-- > 0) {
            reward = bet(i);
            bottom[i] += 1.0;
            if (reward != 0) {
                sum += reward;
                upper[i] = reward;
                break;
            }
        }
        e[i] = upper[i] / bottom[i];
    }
    while (credit-- > 0) { //その時点で期待値が最大のマシーンを回し、逐一期待値を計算する。それを繰り返す。
        int num = max(e[0], e[1], e[2], e[3], e[4]);
        upper[num] += bet(num);
        bottom[num] += 1;
        e[num] = upper[num] / bottom[num];
        sum += bet(num);
    }

    printf("sum = %f\n",(double) sum / N );
        
    return 0;
}
int max(double a, double b, double c, double d, double e) { //期待値最大のマシーンの番号を求める
    double array[] = {a, b, c, d, e};
    int max=0;
    for (int i = 1; i <= 4; i++) {
        if(array[i] > array[max]){
            max = i;
        }
    }
    return max;
}
// 以下の関数は変更不可
int bet(int k){ // 入力：スロットマシンの番号 出力：当選金
    // これは例であり，採点時には当選金と確率が変化する
    switch(k){
        case 0:
            if(rand() % 2 == 0){ // 2/2
                return 2;
            }else{
                return 0;
            }
            break;
        case 1:
            if(rand() % 7 == 0){ // 5/7
                return 5;
            }else{
                return 0;
            }
            break;
        case 2:
            if(rand() % 8 == 0){ // 10/8
                return 10;
            }else{
                return 0;
            }
            break;
        case 3:
            if(rand() % 40 == 0){ // 50/4０
                return 50;
            }else{
                return 0;
            }
            break;
        case 4:
            if(rand() % 200 == 0){  // 100/200
                return 100;
            }else{
                return 0;
            }
            break;
        default:
            return 0;
    }
}