#include <stdio.h>
#include <string.h>

#define MAX 100

enum State { q0, q1, q2, q3, q4, q5, q6 };

int main() {
    char tape[MAX];
    int head = 0;
    enum State state = q0;

    printf("Enter the input string: ");
    scanf("%s", tape);

    strcat(tape, "____________________");

    while (state != q6) {
        char symbol = tape[head];
        switch (state) {
            case q0: // Handle first a's and then move to b's
                if (symbol == 'a') { tape[head] = 'X'; head++; state = q1; }
                else if (symbol == 'X') { head++; }
                else if (symbol == 'b') { state = q4; }  // After a's done, go to b logic
                else if (symbol == 'Y' || symbol == '_') { state = q5; }
                else { printf("\nRejected!\n\nName:Oshin Pant\nRoll no:23\nLab no:9\n Sec:A"); getchar(); getchar(); return 0; }
                break;

            case q1: // Move right until end to find last a
                if (symbol == 'a' || symbol == 'b' || symbol == 'X' || symbol == 'Y') { head++; }
                else if (symbol == '_') { head--; state = q2; }
                break;

            case q2: // Mark last unmarked a as Y
                if (symbol == 'a') { tape[head] = 'Y'; head--; state = q3; }
                else if (symbol == 'Y' || symbol == 'X' || symbol == 'b') { head--; }
                else { printf("\nRejected!\n\nName:Oshin Pant\nRoll no:23\nLab no:9\n Sec:A"); getchar(); getchar(); return 0;}
                break;

            case q3: // Go back to start
                if (symbol == 'X') { head++; state = q0; }
                else { head--; }
                break;

            case q4: // Mark b as X and again find last a -> Y
                if (symbol == 'b') { tape[head] = 'X'; head++; state = q1; }
                else if (symbol == 'X' || symbol == 'Y') { head++; }
                else if (symbol == '_') { state = q5; }
                else { printf("\nRejected!\n\nName:Oshin Pant\nRoll no:23\nLab no:9\n Sec:A"); getchar(); getchar(); return 0;}
                break;

            case q5: // Check if all are X, Y, or _
                if (symbol == 'X' || symbol == 'Y') { head++; }
                else if (symbol == '_') { state = q6; }
                else { printf("\nRejected!\n\nName:Oshin Pant\nRoll no:23\nLab no:9\n Sec:A"); getchar(); getchar(); return 0; }
                break;

            default:
                printf("\nRejected!\n\nName:Oshin Pant\nRoll no:23\nLab no:9\n Sec:A"); getchar(); getchar(); return 0;
        }
    }

    printf("\nAccepted!\n");
    printf("Final tape: %s\n", tape);
    printf("\nName:Oshin Pant\nRoll no:23\nLab no:9\n Sec:A");
    getchar();
    getchar();

    return 0;
}
