#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *create(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (!root)
        return create(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node *search(Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    return search(key < root->data ? root->left : root->right, key);
}

int main()
{
    Node *root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
        root = insert(root, values[i]);

    printf("Inorder traversal: ");
    inorder(root);
    
    printf("\nPreorder traversal: ");
    preorder(root);
    
    printf("\nPostorder traversal: ");
    postorder(root);

    int key = 40;
    printf("\n\n%d %s found\n", key, search(root, key) ? "is" : "is not");

    printf("\nName: Oshin Pant Roll No: 23 Lab No: 16");
    fflush(stdin);
    getchar();
    getchar();
    return 0;
}