#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void SieveOfEratosthenes(long ret_arr[], size_t* ret_len, unsigned long max)
{
    bool* prime = (bool*)malloc(sizeof(bool) * max);
    for (int i = 0; i < max; ++i) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i < max; ++i) {
        if (prime[i]) {
            for (int index = i * 2; index < max; index += i) {
                prime[index] = false;
            }
        }
    }

    for (int i = 0; i < max; ++i) {
        if (prime[i]) {
            *(ret_arr++) = i;
            ++(*ret_len);
        }
    }

    free(prime);
}

int main()
{
    long prime[1000];
    size_t prime_num;
    SieveOfEratosthenes(prime, &prime_num, 1000);
    for (int i = 0; i < prime_num; ++i) {
        printf("%ld\n", prime[i]);
    }
}