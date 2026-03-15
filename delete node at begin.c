#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void deleteAtBeginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void displayNodes(struct node *head) {
    printf("Linked List: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Manually creating nodes as per the notebook code
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *n3 = (struct node*)malloc(sizeof(struct node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    struct node *head = n1;

    printf("Original List:\n");
    displayNodes(head);

    head = head->next; // Note: The code in the image does this manually or calls the function below

    // Using the function defined
    // deleteAtBeginning(&head);

    printf("After deleting first node:\n");
    displayNodes(head);

    return 0;
}
