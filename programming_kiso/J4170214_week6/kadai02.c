#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
int main() {
    struct person {
        char name[20];
        int age;
        double weight;
        double height;
        struct person *next;
    };
    //ファイルの読み込み
    FILE *fp;
    fp=fopen("namelist_short.txt", "r");
    if (fp==NULL) {
        printf("Failed to open the file\n");
        return 1;
    }
    double height1[N], weight1[N];
    double age1[N];
    char name1[N][20];
    int i=0;
    while ((fscanf(fp, "%[^,], %lf, %lf, %lf\n", name1[i], age1+i, height1+i, weight1+i)!=EOF)) {
        i++;
    }
    fclose(fp);
    struct person characters[N];
    //連結リストの作成
    strcpy(characters[0].name, name1[0]);
    characters[0].age=age1[0];
    characters[0].weight=weight1[0];
    characters[0].height=height1[0];
    for (int i=1; i<N-1; i++) {
        characters[i-1].next=&characters[i];
        strcpy(characters[i].name, name1[i]);
        characters[i].age=age1[i];
        characters[i].weight=weight1[i];
        characters[i].height=height1[i];
        characters[i].next=&characters[i+1];
    }
    strcpy(characters[N-1].name, name1[N-1]);
    characters[N-1].age=age1[N-1];
    characters[N-1].weight=weight1[N-1];
    characters[N-1].height=height1[N-1];
    //連結リストの表示
    printf("name, age, weight, height\n");
    for (int i=0; i<N; i++) {
        if (characters[i].age==0) {
            break;
        } else {
            printf("%s, %d, %lf, %lf\n", characters[i].name, characters[i].age, characters[i].weight, characters[i].height);
        }
    }
    return 0;
}
