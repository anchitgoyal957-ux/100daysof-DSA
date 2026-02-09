#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, len;
    char temp;

    printf("Enter the code name:\n");
    scanf("%s", s);

    len = strlen(s);

    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    printf("Mirrored code name:\n");
    printf("%s", s);

    return 0;
}