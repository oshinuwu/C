#include<stdio.h>
#include<math.h>

int main() {
    int num = 1, s, i, y, p, d, count = 0;

    do {
        y = num;
        d = num;
        i = 0;
        p = 0;
        while (num != 0) {
            num = num / 10;
            i++;
        }
        num = d; // Reset num to its original value
        while (y != 0) {
            s = y % 10;
            int r = pow(s, i);
            p = p + r;
            y = y / 10;
        }
        if (p == d) {
            printf("%d\t", d);
            count = count + 1;
        }
       
        num++;
    } while (num <= 5000);
     printf("no of terms is %d\n", count);
    getch();
    return 0;
}
