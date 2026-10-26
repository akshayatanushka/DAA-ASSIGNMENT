
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void sortNodes(struct Node* nodes[], int n) {
    int i, j;
    struct Node* temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq) {
                temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

void displayCodes(struct Node* root, int code[],
                  int top, long long *totalBits) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("%c\t%d\t", root->ch, root->freq);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\t%d\n", top);

        *totalBits += (long long)root->freq * top * 100;
        return;
    }

    code[top] = 0;
    displayCodes(root->left, code, top + 1, totalBits);

    code[top] = 1;
    displayCodes(root->right, code, top + 1, totalBits);
}

int main() {
    char letters[] = {'a', 'c', 'd', 'e', 'o',
                      'm', 's', 't', 'u'};

    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};

    int n = 9;
    struct Node* nodes[100];

    for (int i = 0; i < n; i++)
        nodes[i] = createNode(letters[i], freq[i]);

    while (n > 1) {
        sortNodes(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* parent =
            createNode('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        nodes[0] = parent;

        for (int i = 1; i < n - 1; i++)
            nodes[i] = nodes[i + 1];

        n--;
    }

    int code[100];
    long long totalBits = 0;

    printf("Character\tFrequency\tCode\tLength\n");
    printf("---------------------------------------------\n");

    displayCodes(nodes[0], code, 0, &totalBits);

    printf("\nTotal memory occupied:\n");
    printf("Bits  = %lld bits\n", totalBits);
    printf("Bytes = %.0f bytes\n", totalBits / 8.0);

    return 0;
}