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

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];
    int indegree[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v): ");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    printf("Topological Order: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0)
                enqueue(temp->data);
            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle exists");

    return 0;
}