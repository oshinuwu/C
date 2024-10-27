#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[0]; // Pointer to the first element
    int *ptr2 = &arr[3]; // Pointer to the fourth element
    // Increment and decrement
    printf("Value at ptr1: %d\n", *ptr1);
    ptr1++; // Increment pointer
    printf("Value at ptr1 after increment: %d\n", *ptr1);
    ptr1--; // Decrement pointer
    printf("Value at ptr1 after decrement: %d\n", *ptr1);
    // Addition and subtraction
    printf("Value at ptr2: %d\n", *ptr2);
    ptr2 += 2; // Add 2 to pointer
    printf("Value at ptr2 after addition: %d\n", *ptr2);
    ptr2 -= 2; // Subtract 2 from pointer
    printf("Value at ptr2 after subtraction: %d\n", *ptr2);
    // Subtraction between two pointers
    printf("Difference between ptr2 and ptr1: %ld\n", ptr2 - ptr1);
    // Comparison
    if (ptr1 < ptr2) {
        printf("ptr1 is less than ptr2\n");
    } else if (ptr1 > ptr2) {
        printf("ptr1 is greater than ptr2\n");
    } else {
        printf("ptr1 is equal to ptr2\n");
    }
     printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 13\n"); 
    getch();
    return 0;
}
