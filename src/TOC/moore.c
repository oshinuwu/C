#include <stdio.h>
#include <string.h>

// States
typedef enum { q0, q1, q2, q3 } State;

int main() {
    State state = q0;   // initial state
    char input[100];
    int i;

    printf("Enter binary input string : ");
    scanf("%s", input);

    printf("\nOutput: ");
    // Print initial output based on state
    if (state == q0 || state == q1) printf("0");
    else printf("1");

    for (i = 0; i < strlen(input); i += 2) {
        if (i+1 >= strlen(input)) break;  // avoid incomplete pair

        char a = input[i];
        char b = input[i+1];

        // Transition
        switch (state) {
            case q0:
                if (a=='0' && b=='0') state=q0;
                else if ((a=='0'&&b=='1') || (a=='1'&&b=='0')) state=q3;
                else if (a=='1' && b=='1') state=q1;
                break;

            case q1:
                if ((a=='1'&&b=='0') || (a=='0'&&b=='1')) state=q1;
                else if (a=='0'&&b=='0') state=q3;
                else if (a=='1'&&b=='1') state=q2;
                break;

            case q2:
                if (a=='0'&&b=='0') state=q3;
                else if ((a=='0'&&b=='1') || (a=='1'&&b=='0')) state=q1;
                else if (a=='1'&&b=='1') state=q2;
                break;

            case q3:
                if ((a=='0'&&b=='1') || (a=='1'&&b=='0')) state=q3;
                else if (a=='0'&&b=='0') state=q0;
                else if (a=='1'&&b=='1') state=q1;
                break;
        }

        // Print output based on current state
        if (state == q0 || state == q1) printf("0");
        else printf("1");
    }
    printf("\n");
    printf("\nName:Oshin Pant\nRoll no:23\nLab no:5\n Sec:A");
    getchar();
    getchar();
    return 0;
}