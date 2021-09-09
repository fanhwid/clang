#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 200

int a[N];

void gen_random(int upper_bound)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        a[i] = rand() % upper_bound;
    }
}

void print_random(void)
{
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int howmany(int value)
{
    int cnt = 0, i;
    for (i = 0; i < N; i++) {
        if (value == a[i])
            cnt++;
    }
    return cnt;
}

int main(void)
{
    int i, j, histogram[10] = {};
    gen_random(10);
    for (i = 0; i < N; i++)
        ++histogram[a[i]];
    for (i = 0; i < 10; i++)
        printf("%d\t", i);
    printf("\n");
    i = 0;
    while (i < N) {
        for (j = 0; j < 10; j++) {
            if (histogram[j] > 0) {
                printf("*\t");
                histogram[j]--;
                i++;
            }
            else
                printf(" \t");
        }
        printf("\n");
    }
    return 0;
}