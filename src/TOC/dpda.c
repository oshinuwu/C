#include <stdio.h>
#include <string.h>
#define MAX 100

enum states { q0, q1,q2,q3, qf };

void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states, char, char);

struct stack {
    char symbols[MAX];
    int top;
};
struct stack s;

int main() {
    char input[20];
    enum states curr_state = q0;
    s.top = -1;
    int i = 0;
    char ch = 'e';    // epsilon
    char st_top = 'e';
    
    // Initial epsilon transition: push $ as stack bottom
    curr_state = delta(curr_state, ch, st_top);

    printf("DPDA");
    printf("\nEnter a string of form a^n b^3n: ");
    gets(input);

    ch = input[i];
    st_top = get_stack_top();
    int c = 0;

    while (c <= strlen(input)) {
        curr_state = delta(curr_state, ch, st_top);
        ch = input[++i];
        st_top = get_stack_top();
        c++;
    }

    if (curr_state == qf)
        printf("\nThe string %s is accepted.", input);
    else
        printf("\nThe string %s is not accepted.", input);

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:3-a\n Sec:A");
    getchar();
    getchar();
    return 0;
}

// Delta function for anbn
enum states delta(enum states s, char ch, char st_top) {
    enum states curr_state = s;
    switch (s) {
        case q0:
            if (ch == 'e' && st_top == 'e') {
                curr_state = q1;
                push('$');  // stack bottom marker
            }
            break;

        case q1:
            // Push 'a's onto the stack
            if (ch == 'a') {
                curr_state = q1;
                push('a');
            }
            // Pop 'a's for each 'b'
            else if (ch == 'b' && st_top == 'a') {
                curr_state = q2;  
            }
            else {
                curr_state = s; // reject implicitly by not moving to qf
            }
            break;
        case q2:
            if (ch == 'b' && st_top == 'a') {
                curr_state = q3;
                pop();
            }
            else {
                curr_state = s; // reject implicitly by not moving to qf
            }
            break;
        case q3:
            if (ch == 'b' && st_top == 'a') {
                curr_state = q1;
            }
            // If input finished and stack only has $, accept
            else if (ch == '\0' && st_top == '$') {
                curr_state = qf;
                pop();
            }
            else {
                curr_state = s; // reject implicitly by not moving to qf
            }   

    }
    return curr_state;
}

// Function to get stack top symbol
char get_stack_top() {
    if (s.top == -1)
        return 'e'; // empty stack
    return s.symbols[s.top];
}

// Push function
void push(char ch) {
    if (s.top < MAX - 1) {
        s.symbols[++s.top] = ch;
    } else {
        printf("\nStack Full.");
    }
}

// Pop function
void pop() {
    if (s.top > -1) {
        s.symbols[s.top] = ' ';
        s.top--;
    } else {
        printf("\nStack Empty.");
    }
}