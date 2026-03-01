#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n, k, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *tail = NULL;

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n;

    if(k != 0)
    {
        tail->next = head;

        int steps = n - k;
        temp = head;

        for(i = 1; i < steps; i++)
            temp = temp->next;

        head = temp->next;
        temp->next = NULL;
    }

    temp = head;
    printf("Rotated List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}