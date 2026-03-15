#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertBegin(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    if(head == NULL)
    {
        head = tail = temp;
        temp->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void insertEnd(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    if(head == NULL)
    {
        head = tail = temp;
        temp->next = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
}

void insertAtPos(int x, int pos)
{
    if (pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1)
    {
        insertBegin(x);
        return;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    struct Node *curr = head;

    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
        if (curr == head)
        {
            printf("Position out of bounds\n");
            free(temp);
            return;
        }
    }

    temp->next = curr->next;
    curr->next = temp;

    if (curr == tail)
    {
        tail = temp;
    }
}

void deleteBegin()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head == tail)
    {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = tail = NULL;
    }
    else
    {
        struct Node *temp = head;
        printf("Deleted: %d\n", temp->data);
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deleteEnd()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head == tail)
    {
        printf("Deleted: %d\n", tail->data);
        free(tail);
        head = tail = NULL;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next != tail)
            temp = temp->next;

        printf("Deleted: %d\n", tail->data);
        temp->next = head;
        free(tail);
        tail = temp;
    }
}

void deleteAtPos(int pos)
{
    if (head == NULL || pos < 1)
    {
        printf("List empty or invalid position\n");
        return;
    }
    if (pos == 1)
    {
        deleteBegin();
        return;
    }

    struct Node *curr = head;
    struct Node *prev = NULL;

    for (int i = 1; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
        if (curr == head)
        {
            printf("Position out of bounds\n");
            return;
        }
    }

    printf("Deleted: %d\n", curr->data);
    prev->next = curr->next;

    if (curr == tail)
    {
        tail = prev;
    }
    free(curr);
}

void display()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(Back to Head)\n");
}

int main()
{
    int choice, x, pos;

    while(1)
    {
        printf("\n--- CLL(HEAD & TAIL) ---\n");
        printf("1. Insert Head\n");
        printf("2. Insert Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Head\n");
        printf("5. Delete Tail\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                insertBegin(x);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &x);
                insertEnd(x);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &x, &pos);
                insertAtPos(x, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
