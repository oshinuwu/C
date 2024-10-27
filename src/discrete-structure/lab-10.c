#include <stdio.h>
#define SIZE 9

// Function to initialize bit string representation of a set
void initializeBitString(int universalSet[], int universalSize, int set[], int setSize, int bitString[])
{
    for (int i = 0; i < universalSize; i++)
    {
        bitString[i] = 0; // Initialize all bits to 0
        for (int j = 0; j < setSize; j++) // Check against the given set
        {
            if (universalSet[i] == set[j])
            {
                bitString[i] = 1; // Set the corresponding bit to 1 if found
                break; // Break out of the inner loop
            }
        }
    }
}

// Function to perform union operation
void performUnion(int setA[], int setB[], int unionSet[], int size)
{
    for (int i = 0; i < size; i++)
    {
        unionSet[i] = setA[i] | setB[i]; // Bitwise OR for union
    }
}

// Function to perform intersection operation
void performIntersection(int setA[], int setB[], int intersectionSet[], int size)
{
    for (int i = 0; i < size; i++)
    {
        intersectionSet[i] = setA[i] & setB[i]; // Bitwise AND for intersection
    }
}

int main()
{
    int i, k = 0;

    // Universal set
    int universalSet[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Set A
    int setA[] = {1, 3, 5, 7};
    int sizeA = sizeof(setA) / sizeof(setA[0]);

    // Set B
    int setB[] = {1, 2, 4, 6, 9};
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    // Bit string representations
    int setABitString[SIZE] = {0};
    int setBBitString[SIZE] = {0};
    int unionSetBitString[SIZE] = {0};
    int intersectionSetBitString[SIZE] = {0};

    // Initialize bit string representations
    initializeBitString(universalSet, SIZE, setA, sizeA, setABitString);
    initializeBitString(universalSet, SIZE, setB, sizeB, setBBitString);

    printf("The Bit String representation of setA: ");
    for (i = 0; i < SIZE; i++)
        printf("%d", setABitString[i]);
    printf("\n");

    printf("The Bit String representation of setB: ");
    for (i = 0; i < SIZE; i++)
        printf("%d", setBBitString[i]);
    printf("\n");

    // Perform union operation
    performUnion(setABitString, setBBitString, unionSetBitString, SIZE);

    k = 0;
    int unionSet[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        if (unionSetBitString[i] == 1)
            unionSet[k++] = universalSet[i];
    }

    printf("The union set is: ");
    for (i = 0; i < k; i++)
        printf("%d ", unionSet[i]);
    printf("\n");

    // Perform intersection operation
    performIntersection(setABitString, setBBitString, intersectionSetBitString, SIZE);

    k = 0;
    int intersectionSet[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        if (intersectionSetBitString[i] == 1)
            intersectionSet[k++] = universalSet[i];
    }

    printf("The intersection set is: ");
    for (i = 0; i < k; i++)
        printf("%d ", intersectionSet[i]);
    printf("\n");

     printf("\nName:Oshin Pant Roll No:23 Lab No:10");	 
    getchar();
    return 0;
}
