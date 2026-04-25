#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* n = createNode(v);
    n->next = adj[u];
    adj[u] = n;
}

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data, adj, visited);
        temp = temp->next;
    }

    push(v);
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v): ");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, adj, visited);
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}