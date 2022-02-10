#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arr[7] = {3, 100, 4, 5, 150, 101, 102};
    int n = 7;
    int mpis[7] = {3, 100, 4, 5, 150, 101, 102};

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && mpis[i] < mpis[j] * arr[i])
            {
                mpis[i] = mpis[j] * arr[i];
            }
        }
    }
    int max = mpis[0];
    for (int i = 1; i < n; i++)
    {
        max = max>mpis[i]?max:mpis[i];
    }

    printf("%d", max);
}
