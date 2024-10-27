#include <stdio.h>
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    // Call the Swap function
    Swap(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
      printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 7-a\n"); 
    getch();
    return 0;
}
