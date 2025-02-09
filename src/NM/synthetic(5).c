#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    int a[30], b[30];
    int i, m, n, c;

    // Input for degree of polynomial
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    // Input coefficients of dividend polynomial
    printf("Enter coefficients of dividend polynomial: ");
    for (i = n; i >= 0; i--) {
        scanf("%d", &a[i]);
    }

    // Input constant term of divisor polynomial
    printf("Enter the constant term of divisor polynomial: ");
    scanf("%d", &c);

    // Initialize quotient array
    for (i = 0; i <= n; i++) {
        b[i] = 0;
    }

    // Perform synthetic division
    b[n - 1] = a[n];  // First quotient term
    for (m = n - 1; m > 0; m--) {
        b[m - 1] = a[m] + (b[m] * c);
    }

    // Output Quotient Polynomial
    printf("Quotient: ");
    for (m = n - 1; m >= 0; m--) {
        if (b[m] != 0) {
            if (m > 0)
                printf("%dx^%d + ", b[m], m);
            else
                printf("%d", b[m]);  // Avoid trailing '+'
        }
    }

    getch();
    printf("\n");
    return 0;
}
