#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0; // q0
    printf("DFA_1 (L:w is Divisible by 3)\n");
    printf("Enter a binary string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            if (state == 0) state = 1;
            else if (state == 1) state = 1;
            else if (state == 2) state = 3;
            else if (state == 3) state = 2;
        }
        else if (str[i] == '1') {
            if (state == 0) state = 2;
            else if (state == 1) state = 2;
            else if (state == 2) state = 1;
            else if (state == 3) state = 2;
        }
        else {
            printf("Invalid character!\n");
            return 0;
        }
    }

    printf("\nInput String: %s", str);
    printf("\nFinal State: q%d", state);
    if (state == 1)
        printf("\nResult: ACCEPTED\n");
    else
        printf("\nResult: REJECTED\n");

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:1-a\n Sec:A");
    getchar();
    getchar();
    return 0;
}
