#include <stdio.h>
#include <string.h>

void find_prefix(char str[]);
void find_suffix(char str[]);
void find_substring(char str[], int start, int end);

int main() {
    char str[100];
    int i, j;

    printf("Enter a string: ");
    scanf("%s", str);  // safer than gets()

    printf("\nPrefixes:");
    find_prefix(str);

    printf("\n\nSuffixes:");
    find_suffix(str);

    printf("\nEnter i and j for substring: ");
    scanf("%d%d", &i, &j);
    find_substring(str, i, j);

    printf("\nName:Oshin Pant\nRoll no:23\nLab no:6\n Sec:A");
    getchar();
    getchar();
    return 0;
}

void find_prefix(char str[]) {
    int len = strlen(str);
    for (int i = 1; i <= len; i++) {
        printf("\n%.*s", i, str); // print first i chars
    }
}

void find_suffix(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        printf("\n%s", str + i); // print from position i
    }
}

void find_substring(char str[], int start, int end) {
    int len = strlen(str);
    if (start < 1 || end > len || start > end) {
        printf("\nInvalid positions!");
        return;
    }
    printf("\nSubstring: ");
    for (int i = start - 1; i < end; i++) {
        putchar(str[i]);
    }
    printf("\n");
}
