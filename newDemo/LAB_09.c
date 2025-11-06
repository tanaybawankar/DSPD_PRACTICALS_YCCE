#include <stdio.h>

#define SIZE 7 // Number of slots in the hash table

// Function to calculate hash
int hashFunction(int key)
{
    return key % SIZE;
}

int main()
{
    int hashTable[SIZE];
    int keys[20], n, i, hash, j;

    // Initialize hash table with -1 (empty)
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    // Insert each key using linear probing
    for (i = 0; i < n; i++)
    {
        hash = hashFunction(keys[i]);
        j = 0;

        // Linear probing to find next empty slot
        while (hashTable[(hash + j) % SIZE] != -1)
        {
            j++;
            if (j == SIZE)
            {
                printf("Hash table is full!\n");
                break;
            }
        }

        if (j < SIZE)
            hashTable[(hash + j) % SIZE] = keys[i];
    }

    // Display final hash table
    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Slot %d -> Empty\n", i);
        else
            printf("Slot %d -> %d\n", i, hashTable[i]);
    }

    return 0;
}