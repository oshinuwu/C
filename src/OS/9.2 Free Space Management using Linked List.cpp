#include <stdio.h>
#include <stdlib.h>

struct Node {
    int block;
    struct Node* next;
};

struct Node* createNode(int block) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->block = block;
    newNode->next = NULL;
    return newNode;
}

void displayFreeList(struct Node* head) {
    struct Node* temp = head;
    printf("Free Blocks: ");
    while (temp != NULL) {
        printf("%d ", temp->block);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* allocateBlock(struct Node** head, int block) {
    struct Node *temp = *head, *prev = NULL;
    while (temp != NULL) {
        if (temp->block == block) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;
            printf("Block %d allocated successfully.\n", block);
            free(temp);
            return *head;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Block %d is not free or does not exist.\n", block);
    return *head;
}

struct Node* freeBlock(struct Node* head, int block) {
    struct Node* newNode = createNode(block);
    newNode->next = head;
    printf("Block %d freed successfully.\n", block);
    return newNode;
}

int main() {
    int totalBlocks, i, choice, block;
    struct Node* freeList = NULL;

    printf("Enter total number of blocks: ");
    scanf("%d", &totalBlocks);

    for (i = totalBlocks - 1; i >= 0; i--) {
        struct Node* newNode = createNode(i);
        newNode->next = freeList;
        freeList = newNode;
    }

    do {
        printf("\nFree Space Management Using Linked List\n");
        printf("1. Display Free List\n");
        printf("2. Allocate Block\n");
        printf("3. Free Block\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFreeList(freeList);
                break;
            case 2:
                printf("Enter block number to allocate: ");
                scanf("%d", &block);
                freeList = allocateBlock(&freeList, block);
                break;
            case 3:
                printf("Enter block number to free: ");
                scanf("%d", &block);
                freeList = freeBlock(freeList, block);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

  fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:9-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}

