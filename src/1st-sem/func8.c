#include <stdio.h>

// Declaration of the variable 'total' using 'extern'
extern int total;

// Function declaration to find the sum of two numbers
int sum(int a, int b);

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Call the sum function and store the result in 'total'
    total = sum(num1, num2);
    
    // Print the result stored in 'total'
    printf("Sum of %d and %d is: %d\n", num1, num2, total);
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 8\n"); 
    getch();
    return 0;
}

// Definition of the variable 'total'
int total;

// Function definition to find the sum of two numbers
int sum(int a, int b) {
    return a + b;
}
