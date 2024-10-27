#include <stdio.h>

int main() {
  int prev_prev = 1, prev = 1, curr;
  int n;
  printf("Enter a num n: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    curr = prev + prev_prev;
    printf("%d ", prev_prev);
    prev_prev = prev;
    prev = curr;
  }
   printf("Name:Oshin Pant\n Roll no:19\n Lab no:3-e");
    getch();
  return 0;
}
