#include <stdio.h>

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting (Selection Sort)
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &x);

    // Binary Search (Iterative)
    int left = 0, right = n - 1;
    int found = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == x) {
            found = mid;
            break;
        }
        else if(arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if(found != -1)
        printf("Element found at index: %d\n", found);
    else
        printf("Element not found\n");

    return 0;
}