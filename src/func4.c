#include <stdio.h>
void SortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap arr[i] and arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("enter the value of n");
    scanf("%d",&n);
    int numbers[n];
   printf("enter the numbers");
   for(int i=0;i<n;i++){
    scanf("%d",&numbers[i]);
   }
    int size = sizeof(numbers) / sizeof(numbers[0]);
    SortArray(numbers, size);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:4");
    getch();
    return 0;
}
