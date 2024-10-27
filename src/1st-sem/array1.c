#include <stdio.h>
int main() {
float marks[12];
float total = 0;
int i;
for (i = 0; i < 12; i++) {
printf("Enter mark for student %d: ", i + 1);
scanf("%f", &marks[i]);
while (marks[i] < 0 || marks[i] > 100) {
printf("Marks should be between 0 and 100. Enter again: ");
scanf("%f", &marks[i]);
}
total += marks[i];
}
float average = total / 12;
printf("\nSum of marks: %.2f\n", total);
printf("Average marks: %.2f\n", average);
printf("Name:Oshin Pant\n Roll no:19\n Lab no:1");
getch();
return 0;
}
