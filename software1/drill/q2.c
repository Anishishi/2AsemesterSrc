#include <stdio.h>
int gcd(int array[], int size)
{
    const int result_error = -1;

    if (size == 0) {
        return result_error;
    }

    int gcd = (array[0] < 0 ? -array[0] : array[0]);

    if (gcd == 0) {
        return result_error;
    }

    for (int i = 1; i < size; i++) {
        int num = (array[i] < 0 ? -array[i] : array[i]);

        if (num == 0) {
            return result_error;
        }

        while (num != 0) {
            int tmp = num;
            num = gcd % num;
            gcd = tmp;
        }
    }

    return gcd;
}

int main()
{
    int array[] = {1496, 51, 374, 34};
    printf("gcd=%d\n", gcd(array, sizeof(array) / sizeof(int)));
    return 0;
}