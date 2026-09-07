#include <stdio.h>
struct MinMax {
    int min;
    int max;
};
struct MinMax findMinMax(int a[], int low, int high) {
    struct MinMax result, left, right;
    if (low == high) {
        result.min = a[low];
        result.max = a[low];
        return result;
    }
    if (high == low + 1) {
        if (a[low] < a[high]) {
            result.min = a[low];
            result.max = a[high];
        } else {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }
    int mid = (low + high) / 2;
    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}
int main() {
    int a[100], n, i;
    struct MinMax result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    result = findMinMax(a, 0, n - 1);
    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);
    return 0;
}