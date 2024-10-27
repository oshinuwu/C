#include <stdio.h>

int main() {
    int rows = 5;
    int i, j;

    for (i = 1; i <= rows; i++) {
        // Print spaces
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Print stars
        for (j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }printf("\n");
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-g(vii)");
    getch();
    return 0;
}
