#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

void pop() {
    if (top == -1) {
        return;
    }
    top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    printf("Remaining stack: ");
    display();

    return 0;
}