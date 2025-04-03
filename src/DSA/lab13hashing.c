#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct
{
    int key;
    int value;
} HashEntry;

HashEntry *hashTable[SIZE] = {NULL}; // Initialize all to NULL

int hash(int key)
{
    return key % SIZE;
}

void insert(int key, int value)
{
    int index = hash(key);

    while (hashTable[index] != NULL)
    {
        if (hashTable[index]->key == key)
        {
            hashTable[index]->value = value; // Update if key exists
            return;
        }
        index = (index + 1) % SIZE; // Linear probing
    }

    // Create new entry if key doesn't exist
    HashEntry *newEntry = malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    hashTable[index] = newEntry;
}

int search(int key)
{
    int index = hash(key);
    int start = index;

    do
    {
        if (hashTable[index] != NULL && hashTable[index]->key == key)
        {
            return hashTable[index]->value;
        }
        index = (index + 1) % SIZE;
    } while (index != start); // Stop if we loop back

    return -1; // Not found
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i])
        {
            printf("Index %d: Key=%d, Value=%d\n", i, hashTable[i]->key, hashTable[i]->value);
        }
        else
        {
            printf("Index %d: NULL\n", i);
        }
    }
}

int main()
{
    insert(10, 100);
    insert(20, 200);
    insert(15, 150);
    insert(25, 250); // Collides with 15 (both hash to 5)
    insert(30, 300);

    printf("Hash table:\n");
    display();

    int key = 25;
    int value = search(key);
    printf("\nSearch %d: %s\n", key, value != -1 ? "Found" : "Not found");

    printf("\nName:Oshin Pant Roll No:23 Lab No:13");
    getchar();
    return 0;
}