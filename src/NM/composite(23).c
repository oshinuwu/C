#include <stdio.h>
#include <math.h>

#define f(x) (3*(x)*(x) + 2*(x) - 5)

int main()
{
    float x0, xn, f0, fn, result, h, a;
    int i, k;

    printf("Enter lower limit: ");
    scanf("%f", &x0);

    printf("Enter upper limit: ");
    scanf("%f", &xn);

    printf("Enter value of k (number of subintervals): ");
    scanf("%d", &k);

    if (k <= 0) {
        printf("Error: k must be greater than 0.\n");
        return 1;  // Exit the program
    }

    h = (xn - x0) / k;
    f0 = f(x0);
    fn = f(xn);
    result = f0 + fn;

    for (i = 1; i <= k - 1; i++) {
        a = x0 + i * h;
        result += 2 * f(a);
    }

    result *= h / 2;

    printf("The value of the integration = %f\n", result);

	getchar();
    return 0;
}
