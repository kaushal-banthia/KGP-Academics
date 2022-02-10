#include <stdio.h>
#include <stdlib.h>

int n;
int unimodal(int a[], int low, int high);
int max_x(int arr[][2], int low, int high);
int max_y(int arr[][2], int low, int high);
void main()
{
    printf("QUESTION #1\n_______________________\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the unimodal array elements: ");
    int a[n];
    for (int i = 0; i <n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d", unimodal(a, 0, n-1));

    printf("\n\nQUESTION #2\n_______________________\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n][2];
    printf("Enter the coordinates of the convex polygon in the anti clockwise order");
    for (int i = 0; i < n; i++)
    {
        printf("\nCoordinate number #%d: ", i+1);
        scanf("%d,%d", &arr[i][0], &arr[i][1]);
    }
    int index_x = max_x(arr, 0, n-1);
    int index_y = max_y(arr, 0, n-1);
    printf("\nVertex with maximum x coordinate is: (%d, %d)", arr[index_x][0], arr[index_x][1]);
    printf("\nVertex with maximum y coordinate is: (%d, %d)", arr[index_y][0], arr[index_y][1]);
}

int unimodal(int a[], int low, int high)
{
    if (low >= high)
        return a[low];
    if (high - low == 1)
        return a[low]>a[high]?a[low]:a[high];
    int mid = high + (low -high)/2;
    if (a[mid] > a[mid-1] && a[mid] > a[mid+1])
        return a[mid];
    else if (a[mid] > a[mid-1] && a[mid] < a[mid+1])
        return unimodal(a, mid+1, high);
    else
        return unimodal (a, low, mid-1);
}

int max_x(int arr[][2], int low, int high)
{
    if (low >= high)
        return low;
    if (high - low == 1)
        return arr[low][0]>arr[high][0]?low:high;
    int mid = high + (low -high)/2;
    if (arr[mid][0] > arr[mid-1][0] && arr[mid][0] > arr[mid+1][0])
        return mid;
    else if (arr[mid][0] > arr[mid-1][0] && arr[mid][0] < arr[mid+1][0])
        return max_x(arr, mid+1, high);
    else
        return max_x(arr, low, mid-1);
}

int max_y(int arr[][2], int low, int high)
{
    if (low >= high)
        return low;
    if (high - low == 1)
        return arr[low][1]>arr[high][1]?low:high;
    int mid = high + (low -high)/2;
    if (arr[mid][1] > arr[mid-1][1] && arr[mid][1] > arr[mid+1][1])
        return mid;
    else if (arr[mid][1] > arr[mid-1][1] && arr[mid][1] < arr[mid+1][1])
        return max_y(arr, mid+1, high);
    else
        return max_y(arr, low, mid-1);
}
