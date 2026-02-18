#include <stdio.h>

int main()
{
    int n, k;
    int arr[100], temp[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    for (int i = 0; i < k; i++)
        temp[i] = arr[n - k + i];

    for (int i = n - 1; i >= k; i--)
        arr[i] = arr[i - k];

    for (int i = 0; i < k; i++)
        arr[i] = temp[i];

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}