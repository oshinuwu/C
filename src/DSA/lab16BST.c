#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        // If the tree is empty, create a new node and return it
        return createNode(value);
    }

    // Recursively insert in the left or right subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Visit left subtree
        printf("%d ", root->data);     // Visit root
        inorderTraversal(root->right); // Visit right subtree
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root; // Return the node if found or NULL if not found
    }

    if (key < root->data) {
        return search(root->left, key); // Search in the left subtree
    } else {
        return search(root->right, key); // Search in the right subtree
    }
}

int main() {
    struct Node* root = NULL; // Create an empty BST

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform inorder traversal (displays sorted order)
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the BST.\n", key);
    } else {
        printf("Element %d not found in the BST.\n", key);
    }

    return 0;
}

