#include <stdio.h>

// Iterative Method

void main()
{
    int n;

    printf("Enter a Number : ");
    scanf("%d", &n);

    int i, sum = 0;

    for (i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("Sum is %d", sum);
}

// Recursive Method

int sumOfNaturalNumbers(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumOfNaturalNumbers(n - 1);
}

void main()
{

    int n;

    printf("Enter a Number : ");
    scanf("%d", &n);

    printf("Sum is %d", sumOfNaturalNumbers(n));
}