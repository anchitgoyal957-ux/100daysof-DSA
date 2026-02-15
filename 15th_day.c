#include <stdio.h>

int main() {
    int m, n, i, j, sum = 0;
    int matrix[100][100];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements: %d", sum);

    return 0;
}