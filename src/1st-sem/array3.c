#include <stdio.h>

int main() {
    int arr[15], i, j, temp, num;
    
    printf("Enter the marks: ");
    for (i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array before sorting: ");
    for (i = 0; i < 15; i++) {
        printf("%3d", arr[i]);
    }
    
    // Sorting the array using Bubble Sort
    for (i = 0; i < 14; i++) {
        for (j = 0; j < 14 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("\nThe numbers in descending order are:\n");
    for (i = 14; i >= 0; i--) {
        printf("%3d", arr[i]);
    }
    
    // Printing the second highest mark
    printf("\nThe second highest mark is %d\n", arr[13]);
    
    // Printing the third lowest mark
    printf("The third lowest mark is %d\n", arr[2]);
    
    // Finding highest and lowest value
    printf("\nEnter the number: ");
    scanf("%d", &num);
    printf("The highest value is %d\n", arr[14 - num]);
    printf("The lowest value is %d\n", arr[num - 1]);
    
    printf("\nName = Oshin Pant\nRollno = 19\nLab no = 3\n");
    getch();
    return 0;
}
