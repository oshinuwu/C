#include <stdio.h>
void CalculateSumAndAverage(int marks[], int n) {
    int sum = 0;
    float average;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    average = (float)sum / n;
    printf("Sum of marks: %d\n", sum);
    printf("Average of marks: %.2f\n", average);
}
int main() {
    int studentMarks[15] = {80, 92, 75, 68, 92, 78, 77, 80, 70, 65, 63, 74, 79, 84, 91};
    int selectedMarks[5] = {studentMarks[0], studentMarks[2], studentMarks[4], studentMarks[6], studentMarks[8]};
    int numberOfMarks = 5;
    CalculateSumAndAverage(selectedMarks, numberOfMarks);
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:3");
    getch();
    return 0;
}
