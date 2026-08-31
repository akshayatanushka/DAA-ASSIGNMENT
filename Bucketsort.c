#include <stdio.h>
void bucketSort(int arr[], int n)
{
    int i, j, k;
    int max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int bucket[max + 1];
    for (i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }
    k = 0;
    for (i = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[k] = i;
            k++;
            bucket[i]--;
        }
    }
}
int main()
{
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter non-negative array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}