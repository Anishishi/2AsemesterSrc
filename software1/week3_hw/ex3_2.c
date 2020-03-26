#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int jan(void); 
int main() {
    int ch;
    while ((ch = getchar()) != 'q') {
        if (ch == 'g' || ch == 'G') {
            if (jan() == 1) {
                printf("あなたはグーを出しました。私はチョキを出しました。あなたの勝ち！\n");
            } else if (jan() == 2) {
                printf("あなたはグーを出しました。私はパーを出しました。あなたの負け！\n");
            } else if (jan() == 3) {
                printf("あなたはグーを出しました。私はグーを出しました。あいこですね！\n");
            }
        } else if (ch == 'c' || ch == 'C') {
            if (jan() == 1) {
                printf("あなたはチョキを出しました。私はパーを出しました。あなたの勝ち！\n");
            } else if (jan() == 2) {
                printf("あなたはチョキを出しました。私はグーを出しました。あなたの負け！\n");
            } else if (jan() == 3) {
                printf("あなたはチョキを出しました。私はチョキを出しました。あいこですね！\n");
            }
        } else if (ch == 'p' || ch == 'P') {
            if (jan() == 1) {
                printf("あなたはパーを出しました。私はグーを出しました。あなたの勝ち！\n");
            } else if (jan() == 2) {
                printf("あなたはパーを出しました。私はチョキを出しました。あなたの負け！\n");
            } else if (jan() == 3) {
                printf("あなたはパーを出しました。私はパーを出しました。あいこですね！\n");
            }
        }
    }
    return 0;
}
int jan(void) {
    int i;
    srand(time(NULL));
    i = rand() % 10;
    //80%で勝ち、10%で負け、10%であいこにしてくれる
    if (i < 8) {
        return 1;
    } else if (i ==8) {
        return 2;
    } else {
        return 3;
    }
}