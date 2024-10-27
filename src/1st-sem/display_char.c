// Display characters between user defined range
#include <stdio.h>

int main() {
  char start, end;

  do {
    printf("Enter the starting and ending range of the character display: ");
    scanf("%c %c", &start, &end);

    if (!(start < end)) {
      printf("starting range must be smaller than ending range!!!\n");
    } else
      break;
  } while (1);

  printf("\n-------------\n");

  for (char c = ++start; c != end; c++) {
    printf("%c ", c);
  }printf("\n");
  printf("Name:Oshin Pant\n Roll no:19\n Lab no:3-d");
  getch();
  return 0;
}
