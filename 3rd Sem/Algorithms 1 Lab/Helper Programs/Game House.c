#include <stdio.h>
#include <stdlib.h>

int DFS(int i, int j, int arr[][j]);
int m = 3, n = 3;
void main()
{
    int arr[][3] = {{3, 2 ,1}, {4, 5, 6}, {9, 8, 7}};
    printf("%d", DFS(0, 0, arr));
}

int DFS(int i, int j, int arr[][3])
{
    int right = 0, down = 0;
    if (j+1<n && arr[i][j+1] > arr[i][j])
    {
        right = DFS(i, j+1, arr);
    }
    if (i+1<m && arr[i+1][j] > arr[i][j])
    {
        down = DFS(i+1, j, arr);
    }

    return right>down?(right+1):(down+1);
}
