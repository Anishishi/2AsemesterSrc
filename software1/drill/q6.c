#include <stdio.h>
char *str = "ox";
int checkWin(char c, char state[3][3]) {
	for(int i = 0; i < 3; i++) {
		int ok = 1;
		for(int j = 0; j < 3; j++) {
			if(c != state[i][j])	ok = 0;
		}
		if(ok)	return 1;
	}
	for(int i = 0; i < 3; i++) {
		int ok = 1;
		for(int j = 0; j < 3; j++) {
			if(c != state[j][i])	ok = 0;
		}
		if(ok)	return 1;
	}
	if(state[0][0] == c && state[1][1] == c && state[2][2] == c)	return 1;
	if(state[0][2] == c && state[1][1] == c && state[2][0] == c)	return 1;
	return 0;
}
 
int main(void) {
	char state[3][3] = {"-xo", "xo-", "o--"};
	for(int i = 0; i < 2; i++) {
		if(checkWin(str[i], state)) {
			printf("%c wins!!\n", str[i]);
			return 0;
		}
	}
	printf("draw...\n");
	return 0;
}