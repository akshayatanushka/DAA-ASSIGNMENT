#include <stdio.h>
#include <math.h>

int main()
{
    double x, sum;
    int n;

    printf("Enter the value of X: ");
    scanf("%lf", &x);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (x == 1)
    {
        sum = n;
    }
    else
    {
        sum = (pow(x, n) - 1) / (x - 1);
    }

    printf("Sum of the series = %.2lf\n", sum);

    return 0;
}