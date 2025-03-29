#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = *head;

    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself if it's the first node
        *head = newNode;
        return;
    }

    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = *head;

    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself if it's the first node
        *head = newNode;
        return;
    }

    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Function to insert a node at a given position (1-based index)
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    if (temp->next == *head) {
        *head = NULL;  // Only one node in the list
        free(temp);
        return;
    }

    *head = temp->next;
    last->next = *head;
    free(temp);
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        *head = NULL;  // Only one node in the list
        free(temp);
        return;
    }

    prev->next = *head;
    free(temp);
}

// Function to delete a node from a given position (1-based index)
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    for (int i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function to test the above operations
int main() {
    struct Node* head = NULL;  // Initialize an empty list

    // Perform operations on the circular linked list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtPosition(&head, 25, 3);  // Insert 25 at position 3

    printf("\nAfter inserting nodes:\n");
    displayList(head);

    deleteFromBeginning(&head);
    printf("\nAfter deleting from the beginning:\n");
    displayList(head);

    deleteFromEnd(&head);
    printf("\nAfter deleting from the end:\n");
    displayList(head);

    deleteFromPosition(&head, 2);  // Delete node at position 2
    printf("\nAfter deleting from position 2:\n");
    displayList(head);

    return 0;
}

