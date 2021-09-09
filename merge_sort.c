#include <stdio.h>
#define LEN 8

int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

void merge(int start, int mid, int end)
{
    int n1, n2;
    n1 = mid - start + 1;
    n2 = end - mid;
    int left[n1], right[n2];

    int i, j, k;
    for (i = 0; i < n1; i++) {
        left[i] = a[start + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = a[mid + 1 + j];
    }

    i = j = 0;
    for (k = start; i < n1 && j < n2; k++) {
        if (left[i] < right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
    }

    if (i < n1) {
        a[k] = left[i];
        k++;
    }

    if (j < n2) {
        a[k] = right[j];
        k++;
    }
}

void sort(int start, int end)
{
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        sort(start, mid);
        sort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main(void)
{
    sort(0, LEN - 1);
    int i;
    for (i = 0; i < LEN; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}