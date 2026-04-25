#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        return 0;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int b = pop();
            int a = pop();
            int result;

            if (exp[i] == '+') result = a + b;
            else if (exp[i] == '-') result = a - b;
            else if (exp[i] == '*') result = a * b;
            else result = a / b;

            push(result);
        }
        i++;
    }

    printf("Result: %d", pop());

    return 0;
}