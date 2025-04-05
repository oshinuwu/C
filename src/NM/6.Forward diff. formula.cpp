// WAP to find derivative of a function using two-point forward difference formula
#include <stdio.h>

#define F(x) (3*(x)*(x) + 5*(x) + 1)  // Properly parenthesized

int main() {
    float xi, h, d, f1, f2, x1;

    printf("Enter value of xi and h:\n");
    scanf("%f%f", &xi, &h);

    f1 = F(xi);
    x1 = xi + h;
    f2 = F(x1);

    d = (f2 - f1) / h;

    printf("Derivative is= %.4f\n",d);
    printf("Name: Oshin Pant\nRoll No: 23\nLab No: 6\n");
	fflush(stdin);
	getchar();
	getchar();
    return 0;
}
