#include <stdio.h>
#include <limits.h>

int getmax(int array[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int numbers[] = {12, 34, 56, 78, 91};

int main()
{
    printf("max=%d\n", getmax(numbers, 5));
    return 0;
}