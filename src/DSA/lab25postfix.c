#include <stdio.h>
#include <ctype.h>  // For isdigit()
#include <stdlib.h> // For atof()

#define MAX 100  // Maximum size of stack

// Stack implementation for evaluation
struct Stack {
    int top;
    double arr[MAX];  // Array to store stack elements (double to handle division)
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
void push(struct Stack* stack, double value) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop an element from the stack
double pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    } else {
        printf("Stack underflow!\n");
        return -1;
    }
}

// Function to evaluate a postfix expression
double evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');  // Convert char to int
        } else if (expression[i] == ' ') {
            continue;  // Skip spaces if present
        } else {
            // It's an operator, pop two elements from the stack
            double val2 = pop(&stack);
            double val1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, val1 + val2);
                    break;
                case '-':
                    push(&stack, val1 - val2);
                    break;
                case '*':
                    push(&stack, val1 * val2);
                    break;
                case '/':
                    push(&stack, val1 / val2);
                    break;
            }
        }
    }

    return pop(&stack);  // Return the final result
}

int main() {
    char postfixExpression[] = "23*54*+9-";  // Sample postfix expression

    printf("Postfix Expression: %s\n", postfixExpression);
    double result = evaluatePostfix(postfixExpression);
    printf("Result after evaluation: %.2f\n", result);

    return 0;
}

