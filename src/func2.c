#include <stdio.h>
#include <math.h>
void QuadraticEquation(float a, float b, float c, float *p, float *q) {
    float discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        *p = (-b + sqrt(discriminant)) / (2*a);
        *q = (-b - sqrt(discriminant)) / (2*a);
    } else if (discriminant == 0) {
        *p = *q = -b / (2*a);
    } else {
        *p = *q = 0; // Invalid roots for negative discriminant
    }
}
int main() {
    float a, b, c, root1, root2;
    printf("enter the value of a,b and c");
    scanf("%f%f%f",&a,&b,&c);
    QuadraticEquation(a, b, c, &root1, &root2);
    printf("Roots of the quadratic equation %.1fx^2 + %.1fx + %.1f = 0 are: %.2f and %.2f\n", a, b, c, root1, root2);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:2");
    getch();
    return 0;
}
