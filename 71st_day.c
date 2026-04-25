#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;

    printf("Enter table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &n);

    int table[m];

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < n; i++) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        int h = key % m;

        if (strcmp(op, "INSERT") == 0) {
            int j = 0;
            while (j < m) {
                int idx = (h + j * j) % m;
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                j++;
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int j = 0, found = 0;
            while (j < m) {
                int idx = (h + j * j) % m;
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                if (table[idx] == EMPTY)
                    break;
                j++;
            }
            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}