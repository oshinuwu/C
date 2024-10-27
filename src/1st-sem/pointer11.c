#include <stdio.h>
// Function to calculate the sum of array elements
int CalculateSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}
// Function to calculate the mean of array elements
float CalculateMean(int *arr, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum / size;
}
// Function to sort array elements in descending order
void SortDescending(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) < *(arr + j)) {
                // Swap elements if they are in the wrong order
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
int main() {
    int arr[10];
    int size, sum;
    float mean;
    // Input array elements
    printf("Enter the size of the array (max 10): ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    // Display the sum of array elements
    sum = CalculateSum(arr, size);
    printf("Sum of array elements: %d\n", sum);
    // Display the mean of array elements
    mean = CalculateMean(arr, size);
    printf("Mean of array elements: %.2f\n", mean);
    // Sort array elements in descending order
    SortDescending(arr, size);
    // Display the sorted array
    printf("Array elements in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 11\n"); 
    getch();
    return 0;
}
