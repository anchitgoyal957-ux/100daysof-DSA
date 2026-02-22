#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked list elements:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}