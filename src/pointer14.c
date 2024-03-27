#include <stdio.h>
#include <stdlib.h>

int main() {
    // a. Using malloc() function
    int *ptr_a;
    int size_a = 5;
    ptr_a = (int*)malloc(size_a * sizeof(int)); // Allocating memory for an array of 5 integers

    if (ptr_a == NULL) {
        printf("Memory allocation failed for malloc()\n");
        return 1; // Exit the program if memory allocation fails
    }

    printf("Memory allocated successfully using malloc()\n");

    // Using the allocated memory
    for (int i = 0; i < size_a; i++) {
        ptr_a[i] = i + 1;
        printf("ptr_a[%d] = %d\n", i, ptr_a[i]);
    }

    // b. Using calloc() function
    int *ptr_b;
    int size_b = 5;
    ptr_b = (int*)calloc(size_b, sizeof(int)); // Allocating memory for an array of 5 integers, initialized to 0

    if (ptr_b == NULL) {
        printf("Memory allocation failed for calloc()\n");
        return 1; // Exit the program if memory allocation fails
    }

    printf("\nMemory allocated successfully using calloc()\n");

    // Using the allocated memory
    for (int i = 0; i < size_b; i++) {
        printf("ptr_b[%d] = %d\n", i, ptr_b[i]);
    }

    // c. Using realloc() function
    int size_c = 10;
    ptr_a = (int*)realloc(ptr_a, size_c * sizeof(int)); // Reallocating memory for an array of 10 integers

    if (ptr_a == NULL) {
        printf("Memory reallocation failed for realloc()\n");
        return 1; // Exit the program if memory reallocation fails
    }

    printf("\nMemory reallocated successfully using realloc()\n");

    // Using the reallocated memory
    for (int i = size_a; i < size_c; i++) {
        ptr_a[i] = i + 1;
        printf("ptr_a[%d] = %d\n", i, ptr_a[i]);
    }

    // d. Using free() function
    free(ptr_a); // Freeing the memory allocated using malloc() or realloc()
    free(ptr_b); // Freeing the memory allocated using calloc()

    printf("\nMemory freed successfully using free()\n");
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 14\n"); 
    getch();
    return 0;
}
