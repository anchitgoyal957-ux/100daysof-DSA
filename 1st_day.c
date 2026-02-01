#include <stdio.h>

int main() {
    int n, pos, y;
    int arr[100];

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position : ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &y);

    for (int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = y;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}