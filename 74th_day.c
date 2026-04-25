#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    char votes[n][50];
    int counted[n];

    for (int i = 0; i < n; i++)
        counted[i] = 0;

    printf("Enter votes: ");
    for (int i = 0; i < n; i++)
        scanf("%s", votes[i]);

    int maxCount = 0;
    char winner[50];

    for (int i = 0; i < n; i++) {
        if (counted[i]) continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                count++;
                counted[j] = 1;
            }
        }

        if (count > maxCount || (count == maxCount && strcmp(votes[i], winner) < 0)) {
            maxCount = count;
            strcpy(winner, votes[i]);
        }
    }

    printf("%s %d", winner, maxCount);

    return 0;
}