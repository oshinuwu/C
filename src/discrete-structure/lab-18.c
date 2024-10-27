#include <stdio.h>

// Function to calculate factorial

int factorial(int n)
{

    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

// Function to calculate permutations (nPr)

int permutation(int n, int r)
{

    return factorial(n) / factorial(n - r);
}

// Function to calculate combinations (nCr)

int combination(int n, int r)
{

    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate permutations with repetition (n^r)

int permutationWithRepetition(int n, int r)
{

    int result = 1;

    for (int i = 0; i < r; ++i)
    {

        result *= n;
    }

    return result;
}

int main()
{

    int n, r;

    printf("Enter n: ");

    scanf("%d", &n);

    printf("Enter r: ");

    scanf("%d", &r);

    printf("Permutations (nPr): %d\n", permutation(n, r));

    printf("Combinations (nCr): %d\n", combination(n, r));

    printf("Permutations with Repetition (n^r): %d", permutationWithRepetition(n, r));

    printf("\n\nName : Oshin Pant  Roll no. : 23  Lab 18");
    getch();
    return 0;
}