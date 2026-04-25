#include <stdio.h>
#include <stdlib.h>

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

    n = createNode(u);
    n->next = adj[v];
    adj[v] = n;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m, u, v, s;

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

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS traversal: ");
    dfs(s, adj, visited);

    return 0;
}