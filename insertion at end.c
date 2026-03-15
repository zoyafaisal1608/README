#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void displayNodes(struct node *head) {
    printf("Single Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40); // As per output shown in other notes

    displayNodes(head);
    return 0;
}
