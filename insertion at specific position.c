#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtPosition(struct node **head, int data, int position) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (position == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct node *current = *head;
    for (int i = 1; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range!\n");
        free(temp);
        return;
    }

    temp->next = current->next;
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

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);
    insertAtPosition(&head, 15, 3); // Example based on code logic

    displayNodes(head);
    return 0;
}
