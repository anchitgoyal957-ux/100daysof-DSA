#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, x;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    struct Node *head1 = NULL, *temp1 = NULL;

    printf("Enter elements of first list: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head1 == NULL)
            head1 = temp1 = newNode;
        else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    struct Node *head2 = NULL, *temp2 = NULL;

    printf("Enter elements of second list: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head2 == NULL)
            head2 = temp2 = newNode;
        else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection Point: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}