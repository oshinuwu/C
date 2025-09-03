#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
int pos = 0;

typedef struct Node {
    char symbol[5];
    struct Node *left;
    struct Node *middle;
    struct Node *right;
} Node;

Node* createNode(char *symbol) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->symbol, symbol);
    node->left = node->middle = node->right = NULL;
    return node;
}

int match(char c) {
    if (input[pos] == c) {
        pos++;
        return 1;
    }
    return 0;
}

// Forward declarations
Node* S();
Node* A();
Node* B();

// S → ε | aAS | aB
Node* S() {
    int start = pos;
    Node* node = createNode("S");

    // ε
    if (input[pos] == '\0') return node;

    // aAS
    pos = start;
    if (match('a')) {
        Node* aNode = createNode("a");
        Node* aNode2 = A();
        if (aNode2) {
            Node* sNode = S();
            if (sNode) {
                node->left = aNode;
                node->middle = aNode2;
                node->right = sNode;
                return node;
            }
        }
    }

    // aB
    pos = start;
    if (match('a')) {
        Node* aNode = createNode("a");
        Node* bNode = B();
        if (bNode) {
            node->left = aNode;
            node->right = bNode;
            return node;
        }
    }

    pos = start;
    free(node);
    return NULL;
}

// A → aSa | aS
Node* A() {
    int start = pos;
    Node* node = createNode("A");

    // aSa (longest first)
    if (match('a')) {
        Node* aNode = createNode("a");
        Node* sNode = S();
        if (sNode && match('a')) {
            node->left = aNode;
            node->middle = sNode;
            node->right = createNode("a");
            return node;
        }
        pos = start;
    }

    // aS
    if (match('a')) {
        Node* aNode = createNode("a");
        Node* sNode = S();
        if (sNode) {
            node->left = aNode;
            node->right = sNode;
            return node;
        }
        pos = start;
    }

    free(node);
    return NULL;
}

// B → b
Node* B() {
    if (match('b')) {
        Node* node = createNode("B");
        node->left = createNode("b");
        return node;
    }
    return NULL;
}

// Print parse tree visually (leftmost derivation)
void printParseTree(Node* node, char* prefix, int isTail) {
    if (!node) return;
    printf("%s%s%s\n", prefix, isTail ? "└─ " : "├─ ", node->symbol);

    char newPrefix[256];
    strcpy(newPrefix, prefix);
    strcat(newPrefix, isTail ? "   " : "│  ");

    int childCount = 0;
    if (node->left) childCount++;
    if (node->middle) childCount++;
    if (node->right) childCount++;

    int printed = 0;
    if (node->left) {
        printed++;
        printParseTree(node->left, newPrefix, printed == childCount);
    }
    if (node->middle) {
        printed++;
        printParseTree(node->middle, newPrefix, printed == childCount);
    }
    if (node->right) {
        printed++;
        printParseTree(node->right, newPrefix, printed == childCount);
    }
}

int main() {
    printf("Enter string: ");
    scanf("%99s", input);

    Node* root = S();

    if (root != NULL && input[pos] == '\0') {
        printf("String accepted!\n\nParse Tree:\n");
        printParseTree(root, "", 1);
    } else {
        printf("String not accepted.\n");
    }

    printf("\nName: Oshin Pant\nRoll no: 23\nLab no: 10\nSec: A\n");
    getchar();
    getchar();
    
    return 0;
}
