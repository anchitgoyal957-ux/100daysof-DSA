#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (front == 0 && rear == MAX - 1);
}

void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        printf("No space at front\n");
    } else {
        front--;
        dq[front] = x;
    }
}

void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
        dq[rear] = x;
    }
}

void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void getFront() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
}

void getBack() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
}

void getSize() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }
    printf("%d\n", rear - front + 1);
}

void display() {
    if (isEmpty()) return;
    for (int i = front; i <= rear; i++) {
        printf("%d ", dq[i]);
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') {
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') {
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') {
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') {
            pop_back();
        }
        else if (op[0] == 'f') {
            getFront();
        }
        else if (op[0] == 'b') {
            getBack();
        }
        else if (op[0] == 's') {
            getSize();
        }
    }

    printf("Final deque: ");
    display();

    return 0;
}