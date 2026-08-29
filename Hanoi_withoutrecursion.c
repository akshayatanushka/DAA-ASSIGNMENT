#include <stdio.h>

struct Stack
{
    int n;
    char source;
    char auxiliary;
    char destination;
    int state;
};

int main()
{
    struct Stack stack[100];
    int top = -1;
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    top++;
    stack[top].n = n;
    stack[top].source = 'A';
    stack[top].auxiliary = 'B';
    stack[top].destination = 'C';
    stack[top].state = 0;

    while (top >= 0)
    {
        struct Stack *current = &stack[top];

        if (current->n == 1)
        {
            printf("Move disk 1 from %c to %c\n",
                   current->source, current->destination);
            top--;
        }
        else if (current->state == 0)
        {
            current->state = 1;

            top++;
            stack[top].n = current->n - 1;
            stack[top].source = current->source;
            stack[top].auxiliary = current->destination;
            stack[top].destination = current->auxiliary;
            stack[top].state = 0;
        }
        else
        {
            printf("Move disk %d from %c to %c\n",
                   current->n, current->source, current->destination);

            top--;

            top++;
            stack[top].n = current->n - 1;
            stack[top].source = current->auxiliary;
            stack[top].auxiliary = current->source;
            stack[top].destination = current->destination;
            stack[top].state = 0;
        }
    }

    return 0;
}