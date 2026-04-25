#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;

    return right;
}

int main() {
    int n, a, b;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter two nodes: ");
    scanf("%d %d", &a, &b);

    struct Node* root = buildTree(arr, n, 0);

    struct Node* ans = LCA(root, a, b);

    if (ans != NULL)
        printf("LCA: %d", ans->data);

    return 0;
}