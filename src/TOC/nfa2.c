#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STATES 2  // q0, q1

int main() {
    char str[100];
    printf("Enter a string over {0,1}: ");
    scanf("%s", str);

    int len = strlen(str);
    bool current_states[NUM_STATES] = {false};
    current_states[0] = true;  // Start state q0

    for (int i = 0; i < len; i++) {
        char c = str[i];
        bool next_states[NUM_STATES] = {false};

        // Transitions from q0
        if (current_states[0]) {
            if (c == '0') next_states[0] = true;       // q0->q0 on 0
            if (c == '1') { 
                next_states[0] = true;                // q0->q0 on 1
                next_states[1] = true;                // q0->q1 on 1
            }
        }

        // Transitions from q1
        if (current_states[1]) {
            if (c == '0') next_states[0] = true;       // q1->q0 on 0
        }

        // Update current states
        for (int j = 0; j < NUM_STATES; j++)
            current_states[j] = next_states[j];
    }

    // Check accepting state directly
    if (current_states[1])
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:2-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}
