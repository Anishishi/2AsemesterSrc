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
        int i, j, count;
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
        //ファイルへの書き込み
        FILE *fp;
        if ((fp=fopen("data.txt", "w"))==NULL) {
            printf("Failed to open the file");
            return -1;
        }
        for (int k=0; k<N; k++) {
            count=fprintf(fp, "%s", matrix[k]);
            if (count<0) {
                printf("Failed to write the file");
            }
        }
        fclose(fp);
        while (getchar() != '\n') {
        }
    }
}