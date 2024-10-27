// Use For loop to print multiplication table of user read number
#include <stdio.h>

int main() {
  int input_num;
  printf("Enter a number: ");
  scanf("%d", &input_num);

  printf("Multiplication Table of %d\n", input_num);

  for (int i = 1; i <= 10; i++) {
    printf("%d X %d = %d\n", input_num, i, i * input_num);
  }
  printf("Name:Oshin Pant\n Roll no:19\n Lab no:3-a");
  getch();
  return 0;
}
