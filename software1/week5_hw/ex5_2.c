#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define N 10
char matrix[N][N+1];
int main() {
    int x, y;
    char c;
    //行列の初期化
    memset(matrix, '-', sizeof(matrix));
    //scanfで読み込み
    while (scanf("%d %d %c", &x, &y, &c) != EOF) {
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
    }
}