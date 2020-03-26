#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define N 10
char matrix[N][N+1];
int array[N*N+1];
int survive_die(int, int);
int main() {
    printf("初めに「ライフ」を生成してください。「列 行 *」で入力してください。'列''行'は0~9の整数、'*'はそのままです。複数回入力できます。");
    int x, y;
    char c;
    //行列の初期化
    memset(matrix, '-', sizeof(matrix));
    //scanfで読み込み
    while (scanf("%d %d %c", &x, &y, &c) != EOF) {
        //生存競争開始
        if (x==10 && y==10 && c=='*') {
            system("clear");
            int a, b;
            for (a=0; a<N; a++) {
                for (b=0; b<N; b++) {
                    if (matrix[a][b]=='*') {
                        array[b*10+a]=1;
                    } else if (matrix[a][b]=='-') {
                        array[b*10+a]=0;
                    } else {
                        printf("無効な入力です。");
                        return -1;
                    }
                }
            }
            for (a=0; a<N*N-1; a++) {
                //生存するかしないかを判別する
                if (a==0) {
                    array[a]=survive_die(array[a], array[a+1]+array[a+10]+array[a+11]);
                } else if (a<=8 && a>=1) {
                    array[a]=survive_die(array[a], array[a-1]+array[a+1]+array[a+9]+array[a+10]+array[a+11]);
                } else if (a==9) {
                    array[a]=survive_die(array[a], array[a-1]+array[a+10]+array[a+9]);
                } else if (a==90) {
                    array[a]=survive_die(array[a], array[a-10]+array[a-9]+array[a+1]);
                } else if (a==99) {
                    array[a]=survive_die(array[a], array[a-10]+array[a-9]+array[a-1]);
                } else if (a%10==0) {
                    array[a]=survive_die(array[a], array[a-10]+array[a+1]+array[a+11]+array[a+10]+array[a-9]);
                } else if (a%10==9) {
                    array[a]=survive_die(array[a], array[a-10]+array[a-1]+array[a-11]+array[a+10]+array[a+9]);
                } else if (a<=98 && a>=91) {
                    array[a]=survive_die(array[a], array[a-1]+array[a+1]+array[a-9]+array[a-10]+array[a-11]);
                } else {
                    array[a]=survive_die(array[a], array[a-1]+array[a+1]+array[a-9]+array[a-10]+array[a-11]+array[a+11]+array[a+10]+array[a+9]);
                }
            }
            for (a=0; a<N; a++) {
                for (b=0; b<N; b++) {
                    if (array[b*10+a]==1) {
                        matrix[a][b]='*';
                    } else if (array[b*10+a]==0) {
                        matrix[a][b]='-';
                    }
                }
                printf("%s\n", matrix[a]);
            }
        } else {
            system("clear");
            int i, j;
            for (i=0; i<N; i++) {
                for (j=0; j<=N; j++) {
                    if (i==y && j==x) {
                        matrix[i][j]=c;
                    } else if (j==N) {
                        matrix[i][j]='\0';
                    }
                }
                printf("%s\n", matrix[i]);
            }
            printf("始める時は「10 10 *」を押してください。続けて「ライフ」生成もできます。");
        }
    }
}
int survive_die(int i, int j) {
    if (i==0) {
        if (j==3) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (j==2 || j==3) {
            return 1;
        } else {
            return 0;
        }
    }
}