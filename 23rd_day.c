#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* mergeLists(struct Node *l1, struct Node *l2) {
    struct Node *result = NULL, *tail = NULL;
    while (l1 != NULL && l2 != NULL) {
        struct Node *temp;
        if (l1->data < l2->data) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }
        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    if (l1 != NULL)
        tail->next = l1;
    if (l2 != NULL)
        tail->next = l2;
    return result;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first sorted list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second sorted list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    merged = mergeLists(list1, list2);

    printf("Merged Linked List:\n");
    display(merged);

    return 0;
}