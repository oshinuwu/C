#include <stdio.h>
void Increment() {
    static int count = 0; // Static variable
    count++;
    int x=0;
    x++;
    printf("X:%d\n",x);
    printf("Count: %d\n", count);
}
int main() {
    Increment(); // Count: 1
    Increment(); // Count: 2
    Increment(); // Count: 3
    printf("\nName: Oshin Pant\nRoll no: 19\nLab no: 9\n"); 
    getch();
    return 0;
}
