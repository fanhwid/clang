#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void diamond(int n, char c)
{
    n = abs(n);
    if (n % 2 == 0)
        printf("error, please input an odd number!\n");
    else {
        int m = n / 2;
        int i, j, k;
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= m+1-i; j++)
                printf(" ");
            for (k = 1; k <= 2*i-1; k++)
                printf("%c", c);
            printf("\n");
        }

        for (i = 1; i <= n; i++)
            printf("%c", c);
        printf("\n");
        
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= i; j++)
                printf(" ");
            for (k = 1; k <= 2*m-2*i+1; k++)
                printf("%c", c);
            printf("\n");
        }
    }
}

int main(void)
{
    int i, j;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d\t", i * j);
        }
        printf("\n");
    }
    diamond(13, '+');
    return 0;
}