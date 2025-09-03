#include <stdio.h>
#include <string.h>

char keyword[32][10] = {
    "auto","double","int","struct","break","else","long","switch","case",
    "enum","register","typedef","char","extern","return","union","const",
    "float","short","unsigned","continue","for","signed","void","default",
    "goto","sizeof","volatile","do","if","static","while"
};

enum states { q0, qf, qd };

enum states delta(enum states s, char ch) {
    switch (s) {
        case q0:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_')
                return qf;
            else
                return qd;
        case qf:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || 
                (ch >= '0' && ch <= '9') || ch == '_')
                return qf;
            else
                return qd;
        default:
            return qd;
    }
}

int isKeyword(char str[]) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keyword[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%49s", str);  // safer than just %s

    if (isKeyword(str)) {
        printf("%s is a keyword.\n", str);
    } else {
        enum states curr_state = q0;
        for (int i = 0; str[i] != '\0'; i++)
            curr_state = delta(curr_state, str[i]);

        if (curr_state == qf)
            printf("%s is a valid identifier.\n", str);
        else
            printf("%s is neither keyword nor valid identifier.\n", str);
    }

    printf("\nName: Oshin Pant\nRoll no: 23\nLab no: 8\nSec: A\n");

    // Pause so console doesn't close immediately
    printf("\nPress Enter to exit...");
    getchar(); // consume leftover newline from scanf
    getchar(); // wait for Enter

    return 0;
}
