#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 8  // q0 to q7

bool is_accepting(bool current_states[]) {
    return current_states[7];  // q7 is the accepting state
}

int main() {
    char str[100];
    printf("NFA_1 (L:w={a,b} where w has substring 'aabb' or 'bbaa')");
    printf("\nEnter a string over {a,b}: ");
    scanf("%s", str);

    int len = strlen(str);

    // Initialize current states
    bool current_states[MAX_STATES] = {false};
    current_states[0] = true;  // q0 is start state

    for (int i = 0; i < len; i++) {
        char c = str[i];
        bool next_states[MAX_STATES] = {false};

        // From start state q0, it can loop on any character
        next_states[0] = true;

        // Transitions for "bbaa" (q0-q1-q3-q5-q7)
        if (current_states[0] && c == 'b') next_states[1] = true;  // q0→q1
        if (current_states[1] && c == 'b') next_states[3] = true;  // q1→q3
        if (current_states[3] && c == 'a') next_states[5] = true;  // q3→q5
        if (current_states[5] && c == 'a') next_states[7] = true;  // q5→q7

        // Transitions for "aabb" (q0-q2-q4-q6-q7)
        if (current_states[0] && c == 'a') next_states[2] = true;  // q0→q2
        if (current_states[2] && c == 'a') next_states[4] = true;  // q2→q4
        if (current_states[4] && c == 'b') next_states[6] = true;  // q4→q6
        if (current_states[6] && c == 'b') next_states[7] = true;  // q6→q7

        // Stay in accept state if already there
        if (current_states[7]) next_states[7] = true;

        // Update current states
        for (int j = 0; j < MAX_STATES; j++)
            current_states[j] = next_states[j];
    }

    if (is_accepting(current_states))
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:2-a\n Sec:A");
    getchar();
    getchar();
    return 0;
}
