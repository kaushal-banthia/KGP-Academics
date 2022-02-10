#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    int sum = 0, max = 0, index_start = 0, index_end = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
        {
            sum = 0;
            index_start = i;
        }
        if (sum > max)
        {
            max = sum;
            index_end = i;
        }
    }

    printf("\n%d", max);
    printf("\nThe sub array is from locations %d to %d", index_start, index_end);
}
