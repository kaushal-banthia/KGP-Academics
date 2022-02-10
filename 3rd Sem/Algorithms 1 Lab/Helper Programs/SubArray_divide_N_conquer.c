#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Max_Seg(int arr[], int l, int r);
int Max_Cross_Seg(int arr[], int l, int m, int h);
int upper = 0, lower = 0;

void main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Example Seq: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d",Max_Seg(arr, 0, n-1));
    printf("\nLower: %d, Upper: %d", lower, upper);
}

int Max_Seg(int arr[],int l, int r)
{
    int m = l+ (r-l)/2;
    int max_val;

    if (r==l)
    {
        max_val = arr[l];
    }

    else
    {
        int left_seg_max = Max_Seg(arr, l, m);
        int right_seg_max = Max_Seg(arr, m+1, r);
        int cross_seg_max = Max_Cross_Seg(arr, l, m, r);

        int max = left_seg_max>right_seg_max?left_seg_max:right_seg_max;
        max_val = max>cross_seg_max?max:cross_seg_max;
    }
    return max_val;
}

int Max_Cross_Seg(int arr[], int l, int m, int h)
{
    int sum = 0, left_sum = 0, right_sum = 0;

    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            lower = i;
        }
    }

    sum = 0;

    for (int i = m+1; i <= h; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            upper = i;
        }
    }

    int max = left_sum>right_sum?left_sum:right_sum;
    int max_val = max>(left_sum+right_sum)?max:(left_sum+right_sum);
    return max_val;
}
