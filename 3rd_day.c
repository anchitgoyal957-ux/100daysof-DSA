#include <stdio.h>

int main() {
    int n, k, found = 0;
    int comparisons = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}