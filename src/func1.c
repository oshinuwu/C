#include <stdio.h>
#define PI 3.14159
float AreaOfCircle(float radius) {
    return PI * radius * radius;
}
int main() {
    float radius1 = 4.0, radius2 = 6.0;
    
    printf("Area of circle with radius %.2f: %.2f\n", radius1, AreaOfCircle(radius1));
    printf("Area of circle with radius %.2f: %.2f\n", radius2, AreaOfCircle(radius2));
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:1");
    getch();
    return 0;
    
}
