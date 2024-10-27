// display num between 1 to 100 except those divisible by 2, 3, 4, 5 using
// continue
#include <stdio.h>

int main() {
  for (int i = 6; i < 100; i++) {
    if (i % 2 == 0 || i % 3 == 0 || i % 4 == 0 || i % 5 == 0) {
      continue;
    } else
      printf("%d ", i);
  }printf("\n");
  printf("Name:Oshin Pant\n Roll no:19\n Lab no:5");
  getch();
  return 0;
}
