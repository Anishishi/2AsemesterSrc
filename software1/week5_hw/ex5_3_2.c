#include <stdio.h>
#define N 10
char matrix[N][N+1];
int main() {
    FILE *fp;
    char ch[N*N+1];
    if ((fp=fopen("data.txt", "r"))==NULL) {
        printf("Failed to open the file");
        return -1;
    }
    fscanf(fp, "%s", ch);
    fclose(fp);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            matrix[i][j]=ch[10*i+j];
            matrix[i][N]='\0';
        }
        printf("%s\n", matrix[i]);
    }
    return 0;
}