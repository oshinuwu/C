#include <stdio.h>
int main() {
    int num = 10;
    int *ptr; // Pointer variable to store the address of num
    // Assigning the address of num to ptr
    ptr = &num;
    // Printing the value of num using indirection/dereference operator
    printf("Value of num: %d\n", *ptr);
    // Printing the address of num using address of operator
    printf("Address of num: %p\n", &num);
    printf("Address stored in ptr: %p\n", ptr);
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 10\n"); 
    getch();
    return 0;
}
