#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    int i = size;
    size++;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;

    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void extractMin() {
    if (size <= 0) {
        printf("-1\n");
        return;
    }
    if (size == 1) {
        printf("%d\n", heap[0]);
        size--;
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

void peek() {
    if (size <= 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
}

int main() {
    int n, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'e') {
            extractMin();
        } else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}