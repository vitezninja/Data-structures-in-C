#include "hashTable.h"
#include <math.h>
#include <limits.h>

int covertStringToPreHash(const char *const input);

static char* strings[] = {
    "Hello",
    "World",
    "This",
    "Is",
    "A",
    "Test",
    "String",
    "Array",
    "For",
    "Stack",
    "Implementation",
    "In",
    "C"
};

int main()
{
    HashTable *hashTable = initHashTable();
    if (hashTable == NULL)
    {
        return 1;
    }

    int hashes[13];
    for (size_t i = 0; i < 13; i++)
    {
        hashes[i] = covertStringToPreHash(strings[i]);
        printf("hashes[%d]: %d\n", i, hash(hashes[i], hashTable->size));
    }
    

    for (size_t i = 0; i < 13; i++)
    {
        insert(hashTable, hashes[i], strings[i]);
    }

    printf("Data count: %zu\n", dataCount(hashTable));

    deleteHashTable(hashTable);

    return 0;
}

int covertStringToPreHash(const char *const input)
{
    unsigned long long preHash = 0;
    for (size_t i = 0; input[i] != '\0'; i++)
    {
        preHash += (input[i] - '0') * pow(67, i);

    }
    int result = preHash % 1000000009;

    return result;
}