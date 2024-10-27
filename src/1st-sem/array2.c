#include <stdio.h>
int main() {
int arr[] = {19, 95, 20, 45, 89, 17, 36, 19, 12, 5, 66};
int num, found = 0;
printf("Enter a number: ");
scanf("%d", &num);
for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
if (arr[i] == num) {
found = 1;
break;
}
}
if (found) {
printf("Search is successful.\n");
} else {
printf("Search is unsuccessful.\n");
}
printf("\nName:Oshin Pant\n Roll no:19\n Lab no:2");
getch();
return 0;
}