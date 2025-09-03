#include <stdio.h>
#include <string.h>

// States
typedef enum { q0, q1 } State;

int main() {
    State state = q0;   // initial state
    char input[100];
    int i;

    printf("Enter binary input string (pairs of bits): ");
    scanf("%s", input);

    printf("\nOutput: ");
    for (i = 0; i < strlen(input); i += 2) {
        if (i+1 >= strlen(input)) break;  // avoid incomplete pair

        char a = input[i];
        char b = input[i+1];

        // Transition + Output
        switch (state) {
            case q0:
                if (a=='1' && b=='0') { printf("1"); state=q0; }
                else if (a=='0' && b=='1') { printf("1"); state=q0; }
                else if (a=='0' && b=='0') { printf("0"); state=q0; }
                else if (a=='1' && b=='1') { printf("0"); state=q1; }
                break;

            case q1:
                if (a=='1' && b=='1') { printf("1"); state=q1; }
                else if (a=='1' && b=='0') { printf("0"); state=q1; }
                else if (a=='0' && b=='1') { printf("0"); state=q1; }
                else if (a=='0' && b=='0') { printf("1"); state=q0; }
                break;
        }
    }
    printf("\n");
    printf("\nName:Oshin Pant\nRoll no:23\nLab no:4\n Sec:A");
    getchar();
    getchar();
    return 0;
}