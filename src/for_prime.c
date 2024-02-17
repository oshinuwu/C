#include <stdio.h>

int main() {
  int num, i = 2, rem;
  char prime = 'y';
  printf("enter a number");
  scanf("%d", &num);
  for (int i = 2; i <= num / 2; i++) {
    rem = num % i;
    if (rem == 0) {
      prime = 'n';
      break;
    }
  }
  if (prime == 'y') {
    printf("the number is prime\n ");
  } else {
    printf("the number is not prime\n");
  }
  printf("Name:Oshin Pant\n Roll no:19\n Lab no:3-b");
  getch();
  return 0;
}
