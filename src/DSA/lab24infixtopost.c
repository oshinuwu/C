#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Simplified stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX-1) stack[++top] = c;
    else printf("Stack overflow\n");
}

char pop() {
    if (top >= 0) return stack[top--];
    printf("Stack underflow\n");
    return '\0';
}

char peek() {
    return (top >= 0) ? stack[top] : '\0';
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    switch(op) {
        case '^': return 4;
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        default: return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top != -1) pop(); // Remove '(' from stack
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%99s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    
    printf("\nName:Oshin Pant Roll No:23 Lab No:24");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}