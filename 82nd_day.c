#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int l = 0, r = n - 1, ans = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int upperBound(int arr[], int n, int x) {
    int l = 0, r = n - 1, ans = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] > x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, x;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    printf("%d %d", lowerBound(arr, n, x), upperBound(arr, n, x));

    return 0;
}