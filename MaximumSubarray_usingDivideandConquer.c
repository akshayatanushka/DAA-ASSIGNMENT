#include <stdio.h>
#include <limits.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int maxCrossingSum(int a[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int i;
    for (i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++) {
        sum += a[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubarraySum(int a[], int low, int high) {
    int mid;
    int leftSum, rightSum, crossSum;
    if (low == high)
        return a[low];
    mid = (low + high) / 2;
    leftSum = maxSubarraySum(a, low, mid);
    rightSum = maxSubarraySum(a, mid + 1, high);
    crossSum = maxCrossingSum(a, low, mid, high);
    return max(max(leftSum, rightSum), crossSum);
}
int main() {
    int a[100], n, i;
    int result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    result = maxSubarraySum(a, 0, n - 1);
    printf("Maximum subarray sum = %d\n", result);
    return 0;
}