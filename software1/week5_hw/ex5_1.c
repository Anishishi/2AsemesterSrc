#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define N 10
int main() {
    char matrix[N][N+1];
    memset(matrix, ' ', sizeof(matrix));
    for (int i=0; i<N; i++) {
        system("clear");
        matrix[i][i]='*';
        for (int x=0; x<N; x++) {
            for (int y=0; y<N; y++) {
                printf("%c", matrix[x][y]);
            }
            printf("\n");
        }
        sleep(1);
    }
    while (getchar() != EOF) {
    }
}