#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum State { q0, q1, q2, q3, q4, trap };

int main() {
    char phone[50];
    enum State state = q0;
    int i;

    printf("Enter a 10-digit Nepali phone number: ");
    scanf("%s", phone);

    int len = strlen(phone);

    for (i = 0; i < len; i++) {
        char ch = phone[i];
        if (!isdigit(ch)) { state = trap; break; }

        switch (state) {
            case q0:
                if (ch == '9') state = q1;
                else state = trap;
                break;

            case q1:
                if (ch == '8' || ch == '7' || ch == '6') state = q2;
                else state = trap;
                break;

            case q2:
                state = q3; // 3rd digit
                break;

            case q3:
                state = q3; // keep reading digits
                break;

            default:
                state = trap;
        }

        if (state == trap) break;
    }

    // Final check
    if (state == q3 && len == 10)
        state = q4;

    if (state == q4)
        printf("Valid Nepali Phone Number!\n");
    else
        printf("Invalid Phone Number!\n");

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:7\n Sec:A");
    getchar();
    getchar();
    return 0;
}
