#include <stdio.h>
int main() {
    //データの読み込み
    FILE *fp1;
    if ((fp1=fopen("data.txt", "r")) == NULL) {
        printf("Failed to open the file");
        return -1;
    }
    int i=0, j=0, k, l=0;
    while (getc(fp1) != EOF) {
        i++;
    }
    fseek(fp1, 0, SEEK_SET);
    char ch[i+1];
    int out[i+2];
    fscanf(fp1, "%s", ch);
    fclose(fp1);
    //データの圧縮(課題5で用いることも考え、圧縮するデータは'A'と'B'の連続するデータと考え、初めに'A'が来ると仮定して'A''B'の来る数を記録していく)
    if (ch[0]=='B') {
        out[0]=0;
        l++;
    }
    while (ch[j]!='\0') {
        if (ch[j]=='A') {
            k=1;
            while (ch[j+k]=='A') {
                k++;
            }
            out[l]=k;
            j=j+k;
            l++;
        } else if (ch[j]=='B') {
            k=1;
            while (ch[j+k]=='B') {
                k++;
            }
            out[l]=k;
            j=j+k;
            l++;
        }
    }
    out[l]='\0';
    //圧縮データの書き込み
    FILE *fp2;
    if ((fp2=fopen("data_compressed_txt", "w")) == NULL) {
        printf("Failed to write the file");
        return -2;
    }
    for (int i=0; i<l; i++) {
        fprintf(fp2, "%d,", *(out+i));
    }
    fclose(fp2);
    return 0;
}