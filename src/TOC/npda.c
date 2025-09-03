#include <stdio.h>
#include <string.h>
#define MAX 100
#define N 5

enum states { q0, q1, qf };

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
    enum states curr_state[N];
    s.top = -1;
    int i = 0;
    char ch = 'e';    // epsilon
    char st_top = 'e';
    
    // Initial epsilon transition: push $ as stack bottom
    curr_state[N] = delta(curr_state, ch, st_top);

    printf("NPDA");
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

    if (curr_state[N] == qf)
        printf("\nThe string %s is accepted.", input);
    else
        printf("\nThe string %s is not accepted.", input);

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:3-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}

// Delta function for anbn
enum states delta(enum states s, char ch, char st_top) {
    enum states curr_state[2] = s;
    switch (s) {
        case q0:
            if (ch == 'e' && st_top == 'e') {
                curr_state[0] = q0;
                push('$');  // stack bottom marker
            }
            // Push 'a's onto the stack
            if (ch == 'a') {
                curr_state[0] = q0;
                push('a');
            }
            if (ch == 'b' && st_top == 'a') {
                curr_state[1] = q1;  
            }
            break;
            

        case q1:
            
            if (ch == 'b' && st_top == 'a') {
                curr_state[1] = q1 || curr_state[1] = q1 && pop();
            }
            else if (ch == '\0' && st_top == '$') {
                curr_state[3] = qf;
                pop();
            }
            else {
                curr_state[3] = s; // reject implicitly by not moving to qf
            }
            break;
       
    return curr_state;
}
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