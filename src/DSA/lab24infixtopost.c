#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isalnum()
#include <string.h> // For strlen()

#define MAX 100  // Maximum stack size

// Stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    } else {
        printf("Stack underflow!\n");
        return -1;
    }
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;  // For '('
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int k = 0;  // Index for postfix array

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(&stack, ch);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (ch == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop '('
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top]) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';  // Null terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

