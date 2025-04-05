#include <stdio.h>
#include <ctype.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double val) {
    if (top < MAX-1) stack[++top] = val;
    else printf("Stack overflow\n");
}

double pop() {
    if (top >= 0) return stack[top--];
    return 0;
}

double evaluate(char* expr) {
    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else if (expr[i] != ' ') {
            double b = pop(), a = pop();
            switch(expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[] = "27$54/+9*"; 
    
    printf("Postfix: %s\n", expr);
    printf("Result: %.2f\n", evaluate(expr));
    
    printf("\nName: Oshin Pant Roll No: 23 Lab No: 25");
    getchar();
    return 0;
}