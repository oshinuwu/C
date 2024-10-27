#include <stdio.h>
int Factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d: %d\n", num, Factorial(num));
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-a");
    getch();
    return 0;
}
