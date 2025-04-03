#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = new;  // Circular by default
    return new;
}

void insert_at_beginning(Node** head, int data) {
    Node* new = create_node(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    
    new->next = *head;
    Node* last = *head;
    while (last->next != *head) last = last->next;
    last->next = new;
    *head = new;
}

void insert_at_end(Node** head, int data) {
    if (*head == NULL) {
        insert_at_beginning(head, data);
        return;
    }
    
    Node* new = create_node(data);
    Node* last = *head;
    while (last->next != *head) last = last->next;
    
    last->next = new;
    new->next = *head;
}

void delete_from_beginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* last = *head;
    while (last->next != *head) last = last->next;
    
    Node* temp = *head;
    if (last == *head) {  // Only one node
        *head = NULL;
    } else {
        *head = (*head)->next;
        last->next = *head;
    }
    free(temp);
}

void delete_from_end(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node *last = *head, *prev = NULL;
    while (last->next != *head) {
        prev = last;
        last = last->next;
    }
    
    if (prev == NULL) {  // Only one node
        *head = NULL;
    } else {
        prev->next = *head;
    }
    free(last);
}

void delete_from_position(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (pos == 1) {
        delete_from_beginning(head);
        return;
    }
    
    Node *current = *head, *prev = NULL;
    int count = 1;
    do {
        prev = current;
        current = current->next;
        count++;
    } while (current != *head && count < pos);
    
    if (current == *head) {
        printf("Position out of range\n");
        return;
    }
    
    prev->next = current->next;
    free(current);
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* current = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

void free_list(Node** head) {
    if (*head == NULL) return;
    
    Node* current = (*head)->next;
    while (current != *head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}

int main() {
    Node* head = NULL;
    
    // Insert operations
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    
    printf("After inserts:\n");
    display(head);
    
    // Delete operations
    delete_from_beginning(&head);
    printf("\nAfter deleting from beginning:\n");
    display(head);
    
    delete_from_end(&head);
    printf("\nAfter deleting from end:\n");
    display(head);
    
    delete_from_position(&head, 2);
    printf("\nAfter deleting from position 2:\n");
    display(head);
    
    free_list(&head);

    printf("\nName:Oshin Pant Roll No:23 Lab No:18");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}