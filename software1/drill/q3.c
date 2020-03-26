#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10000; i++) {
        printf("%i,%i,%i\n", rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1);
    }

    return 0;
}