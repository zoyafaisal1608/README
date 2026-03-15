#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void deleteLast() {
    struct node *current, *temp;

    if (head == NULL) {
        printf("Nothing to delete\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    temp = current->next;
    current->next = NULL;
    free(temp);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40); // Inferred from output

    printf("Before deletion: ");
    display();

    deleteLast();

    printf("After deletion: ");
    display();

    return 0;
}
