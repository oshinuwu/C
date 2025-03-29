#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Define the size of the hash table

// Structure to store a key-value pair
typedef struct {
    int key;
    int value;
} HashEntry;

// Hash table initialization
HashEntry* hashTable[SIZE];

// Function to create a new hash entry
HashEntry* createEntry(int key, int value) {
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    return newEntry;
}

// Hash function to map keys to indices
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert key-value pair into hash table using linear probing
void insert(int key, int value) {
    int index = hashFunction(key);

    while (hashTable[index] != NULL && hashTable[index]->key != key) {
        index = (index + 1) % SIZE;  // Linear probing
    }

    if (hashTable[index] != NULL) {
        printf("Updating key %d at index %d\n", key, index);
    } else {
        printf("Inserting key %d at index %d\n", key, index);
    }
    hashTable[index] = createEntry(key, value);
}

// Function to search for a value by key
int search(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[index] == NULL) {
            return -1;  // Key not found
        }
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % SIZE;  // Linear probing
    }
    return -1;  // Key not found
}

// Function to display the hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}

int main() {
    // Initializing the hash table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Inserting key-value pairs
    insert(10, 100);
    insert(20, 200);
    insert(15, 150);
    insert(25, 250);  // Causes a collision with key 15
    insert(30, 300);

    // Displaying the hash table
    printf("\nHash table after insertions:\n");
    display();

    // Searching for a key
    int keyToSearch = 15;
    int value = search(keyToSearch);
    if (value != -1) {
        printf("\nFound value %d for key %d\n", value, keyToSearch);
    } else {
        printf("\nKey %d not found in hash table.\n", keyToSearch);
    }

    return 0;
}

