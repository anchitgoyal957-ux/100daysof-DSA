#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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

struct Node* queue[MAX];
int front = 0, rear = -1;

void enqueue(struct Node* x) {
    queue[++rear] = x;
}

struct Node* dequeue() {
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

    if (root == NULL) return 0;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left)
                enqueue(temp->left);
            if (temp->right)
                enqueue(temp->right);
        }
    }

    return 0;
}