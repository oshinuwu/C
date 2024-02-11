#include <stdio.h>

int main() {
    int sum = 0;
    int a;

    while (1) {
        printf("Enter an integer: ");
        if (scanf("%d", &a) != 1) {
            while (getchar() != '\n');
            continue;
        }

        sum += a;

        int primw = 1;

        if (a < 2) {
            primw = 0;
        } else {
            for (int i = 2; i * i <= a; i++) {
                if (a % i == 0) {
                    primw = 0;
                    break;
                }
            }
        }

        if (primw) {
            break;
        }
    }

    printf("Sum: %d\n", sum);
    getch();
    return 0;
}