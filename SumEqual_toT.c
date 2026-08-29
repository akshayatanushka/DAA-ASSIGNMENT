#include <stdio.h>

#define SIZE 1000

int hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = 0;
}

int hashFunction(int key) {
    if (key < 0)
        key = -key;

    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != 0) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

int search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != 0) {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return 0;
}

int main() {
    int n, T;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target value T: ");
    scanf("%d", &T);

    initialize();

    for (int i = 0; i < n; i++) {
        int needed = T - arr[i];

        if (search(needed)) {
            printf("Pair found: %d + %d = %d\n",
                   needed, arr[i], T);
            return 0;
        }

        insert(arr[i]);
    }

    printf("No such pair exists.\n");

    return 0;
}