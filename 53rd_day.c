#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);
    return root;
}

struct QNode queue[MAX];
int front = 0, rear = -1;

void enqueue(struct Node* node, int hd) {
    queue[++rear].node = node;
    queue[rear].hd = hd;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int col[2 * MAX][MAX];
    int count[2 * MAX] = {0};

    int offset = MAX;

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd;

        col[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, hd - 1);
        if (curr->right)
            enqueue(curr->right, hd + 1);
    }

    for (int i = 0; i < 2 * MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", col[i][j]);
            printf("\n");
        }
    }

    return 0;
}