#include <stdio.h>
#include<conio.h>

void fibonacci(int n, int a, int b) {
    if (n <= 0)
        return;
    
    printf("%d ", a);
    fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    
    // Taking input from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    fibonacci(n, 0, 1);
    
    printf("\nName:Oshin Pant Roll No:23 Lab No:4");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}