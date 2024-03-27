#include <stdio.h>

int IsEven(int num) {
    return (num % 2 == 0) ? 1 : 0;
}

void PrintMultiplicationTable(int num) {
    printf("Multiplication table of %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int IsPalindrome(int num) {
    int reversedNum = 0, originalNum = num;
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return (originalNum == reversedNum) ? 1 : 0;
}

int main() {
    char choice;
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Enter choice (E - Even/Odd, M - Multiplication table, P - Palindrome): ");
    scanf(" %c", &choice);  // note the space before %c to consume any leading whitespace
    
    switch (choice) {
        case 'E':
        case 'e': // Allow lowercase 'e' as well
            if (IsEven(num)) {
                printf("%d is even.\n", num);
            } else {
                printf("%d is odd.\n", num);
            }
            break;
        case 'M':
        case 'm': // Allow lowercase 'm' as well
            PrintMultiplicationTable(num);
            break;
        case 'P':
        case 'p': // Allow lowercase 'p' as well
            if (IsPalindrome(num)) {
                printf("%d is a palindrome.\n", num);
            } else {
                printf("%d is not a palindrome.\n", num);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:5");
    getch();
    return 0;
}
