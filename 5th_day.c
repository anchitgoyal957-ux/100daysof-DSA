#include <stdio.h>

int main() {
    int p, q, i = 0, j = 0;

    printf("Enter number of entries in server log 1:\n");
    scanf("%d", &p);

    int a[p];
    printf("Enter arrival times for server log 1 (sorted):\n");
    for (int k = 0; k < p; k++)
        scanf("%d", &a[k]);

    printf("Enter number of entries in server log 2:\n");
    scanf("%d", &q);

    int b[q];
    printf("Enter arrival times for server log 2 (sorted):\n");
    for (int k = 0; k < q; k++)
        scanf("%d", &b[k]);

    printf("Merged chronological log:\n");

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}