#include <stdio.h>
void IncrementByFive(int *a, int *b) {
    *a += 5;
    *b += 5;
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    // Increment both numbers by 5
    IncrementByFive(&num1, &num2);
    // Display their sum
    printf("Sum of numbers after incrementing by 5: %d\n", num1 + num2);
     printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 7-c\n"); 
    getch();
    return 0;
}
