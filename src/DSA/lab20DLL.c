#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

Node* create_node(int data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = new->prev = NULL;
    return new;
}

void insert_front(Node** head, int data) {
    Node* new = create_node(data);
    if (*head) {
        new->next = *head;
        (*head)->prev = new;
    }
    *head = new;
}

void insert_end(Node** head, int data) {
    Node* new = create_node(data);
    if (!*head) {
        *head = new;
        return;
    }
    
    Node* curr = *head;
    while (curr->next) curr = curr->next;
    curr->next = new;
    new->prev = curr;
}

void delete_front(Node** head) {
    if (!*head) return;
    
    Node* temp = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(temp);
}

void delete_end(Node** head) {
    if (!*head) return;
    
    if (!(*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }
    
    Node* curr = *head;
    while (curr->next) curr = curr->next;
    curr->prev->next = NULL;
    free(curr);
}

void delete_node(Node** head, int data) {
    if (!*head) return;
    
    Node* curr = *head;
    while (curr && curr->data != data) curr = curr->next;
    
    if (!curr) return; // Not found
    
    if (curr == *head) {
        delete_front(head);
    } else if (!curr->next) {
        delete_end(head);
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}

void print_list(Node* head, int reverse) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    
    if (reverse) {
        while (head->next) head = head->next;
        while (head) {
            printf("%d ", head->data);
            head = head->prev;
        }
    } else {
        while (head) {
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}

void free_list(Node** head) {
    while (*head) delete_front(head);
}

int main() {
    Node* head = NULL;
    
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_front(&head, 5);
    
    printf("forward list: ");
    print_list(head, 0); // Forward: 5 10 20
    printf("Reverse list: ");
    print_list(head, 1); // Reverse: 20 10 5
    
    delete_front(&head); // Removes 5
    delete_end(&head);   // Removes 20
    printf("After deletion: ");
    print_list(head, 0); 

    delete_node(&head, 10); // Removes 10
    
    printf("After deletion of node: ");
    print_list(head, 0); // List is empty
    
    free_list(&head);

    printf("\nName:Oshin Pant Roll No:23 Lab No:20");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}