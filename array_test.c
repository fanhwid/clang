#include <stdio.h>
#include <math.h>

int main(void)
{
    int a[4] = {1, 2, 3, 4};
    int b[4];
    int i;
    for (i = 0; i < 4; i++) {
        printf("a[%d]:%d\n", i, a[i]);
    }
    for (i = 0; i < 4; i++) {
        b[i] = a[i];
        printf("b[%d]:%d\n", i, b[i]);
    }
    return 0;
}