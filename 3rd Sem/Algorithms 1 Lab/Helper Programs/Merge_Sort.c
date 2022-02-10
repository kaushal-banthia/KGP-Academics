#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nMerged Array is : ");
    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m+1;

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
