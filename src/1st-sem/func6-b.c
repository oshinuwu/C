#include <stdio.h>

void Fibonacci(int n) {
    int prev_prev = 1, prev = 1, curr;
    
    if (n <= 1) {
        printf("%d", prev);
    } else {
        for (int i = 0; i < n; i++) {
            curr = prev + prev_prev;
            printf("%d ", prev_prev);
            prev_prev = prev;
            prev = curr;
        }
    }
}

int main() {
    int n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("The %d terms of the Fibonacci sequence: ", n); 
    Fibonacci(n);
    
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 6-b\n"); 
    getch();
    return 0;
}
