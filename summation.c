#include <stdio.h>
int main()
{
    int n, i;
    double x, term = 1, sum = 0;

    printf("Enter the value of X: ");
    scanf("%lf", &x);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        sum = sum + term;
        term = term * x;
    }

    printf("Sum of the series = %.2lf\n", sum);

    return 0;
}