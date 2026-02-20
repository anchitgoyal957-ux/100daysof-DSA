#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == 0)
            count++;

        for (int j = i + 1; j < n; j++)
        {
            if (prefix[i] == prefix[j])
                count++;
        }
    }

    printf("Number of subarrays with sum zero: %d\n", count);

    return 0;
}