#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_from_beginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_from_end(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
}

void display_list(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void free_list(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    Node *head = NULL;
    
    // Insert operations
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    
    printf("After inserting at the beginning\n");
    display_list(head);
    
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    printf("\nAfter inserting at the end\n");
    display_list(head);

    // Delete operations
    delete_from_beginning(&head);
    printf("\nAfter deleting from beginning:\n");
    display_list(head);
    
    delete_from_end(&head);
    printf("\nAfter deleting from end:\n");
    display_list(head);
    
    // Free all memory before exiting
    free_list(&head);
    
    printf("\nName:Oshin Pant Roll No:23 Lab No:17");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}