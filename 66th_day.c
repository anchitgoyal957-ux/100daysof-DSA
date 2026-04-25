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
}

int dfs(int v, struct Node* adj[], int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int x = temp->data;
        if (!visited[x] && dfs(x, adj, visited, recStack))
            return 1;
        else if (recStack[x])
            return 1;
        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];
    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v): ");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}