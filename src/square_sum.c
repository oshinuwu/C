// Calculate sum of first n squares

#include <stdio.h>

int main() {
  unsigned int n, sum = 0;
  printf("Input +ve integer n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    sum += i * i;
  }

  printf("%d is the sum\n", sum);
  printf("Name:Oshin Pant\n Roll no:19\n Lab no:3-c");
  getch();
  return 0;
}
