#include <stdio.h>
void FindLargest(int *a, int *b, int *c) {
    if (*a >= *b && *a >= *c) {
        printf("Largest number: %d\n", *a);
    } else if (*b >= *a && *b >= *c) {
        printf("Largest number: %d\n", *b);
    } else {
        printf("Largest number: %d\n", *c);
    }
}
int main() {
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    // Call the FindLargest function
    FindLargest(&num1, &num2, &num3);
     printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 7-b\n"); 
    getch();
    return 0;
}
