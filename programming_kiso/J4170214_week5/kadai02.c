#include <stdlib.h>
#include <stdio.h>
#define N 10000
int main() {
    FILE *fp1=fopen("sentence.txt", "r");
    if (fp1==NULL) {
        printf("Failed to open the file\n");
        return 1;
    }
    int i=0;
    char cset[N];
    while ((cset[i]=getc(fp1)) != EOF) {
        i++;
    }
    cset[0]=cset[0]-32;
    for (int j=2; cset[j] != '\0'; j++) {
        if (cset[j]=='i' && cset[j-1]==' ' && cset[j+1]==' ') {
            cset[j]=cset[j]-32;
        } else if (cset[j-2]=='.') {
            cset[j]=cset[j]-32;
        } else if (cset[j]=='i' && cset[j-1]==' ' && cset[j+1]=='\'') {
            cset[j]=cset[j]-32;
        }
    }
    fclose(fp1);
    FILE *fp2=fopen("sentence_coverted.txt", "w");
    if (fp2==NULL) {
        printf("Failed to open the file\n");
        return -1;
    }
    fputs(cset, fp2);
    fclose(fp2);
    return 0;
}