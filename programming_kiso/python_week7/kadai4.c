#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char**argv)
{
    if (argc != 2){
        printf("You have to decide the number of 'q'\n");
        return -1;
    }
    const double q = atof(argv[1]);
    if (q<0 || q>1){
        printf("0 <= q <= 1 is not satisfied\n");
        return -1;
    }
    int steps = 1000000;//step回数
    int distance = 0;//移動した距離
    int counter = 0;
    int flag = 0;//状態が2パターンある
    srand(time(NULL));
    while (counter!=steps){
        double temp=(double)rand()/(RAND_MAX+1.0);//0~1の間の乱数の取得
        if (flag==0){//確率qで1進む
            if (temp<q){
                distance++;
                flag=1;
            }
        }else{//flag==1の時で半分の確率で前後する
            if (temp<0.5){
                distance--;
            }else{
                distance++;
            }
            flag=0;
        }
        counter++;
    }
    distance = abs(distance);
    printf("%f", (double)distance/steps);
    return 0;
}