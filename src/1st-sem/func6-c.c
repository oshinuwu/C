#include <stdio.h>
float Power(float base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent > 0) {
        return base * Power(base, exponent - 1);
    } else {
        // Handling negative exponent
        return 1 / Power(base, -exponent);
    }
}
int main() {
    float base;
    int exponent;
    printf("Enter the base: ");
    scanf("%f", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    printf("%.2f^%d = %.2f\n", base, exponent, Power(base, exponent));
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 6-c\n"); 
    getch();
    return 0;
}

