#include <stdio.h>

#define SIZE 1000

struct Hash {
    int key;
    int frequency;
};

struct Hash table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        table[i].key = -1;
        table[i].frequency = 0;
    }
}

int hashFunction(int key) {
    if (key < 0)
        key = -key;

    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (table[index].key != -1 && table[index].key != key) {
        index = (index + 1) % SIZE;
    }

    if (table[index].key == key) {
        table[index].frequency++;
    } else {
        table[index].key = key;
        table[index].frequency = 1;
    }
}

void display() {
    printf("\nFrequency of elements:\n");

    for (int i = 0; i < SIZE; i++) {
        if (table[i].key != -1)
            printf("%d -> %d\n",
                   table[i].key,
                   table[i].frequency);
    }
}

int main() {
    int n;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insert(arr[i]);
    }

    display();

    return 0;
}