#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void print_all_paths(int sx, int sy, int fx, int fy, int n, int X[n][n], bool visited[n][n], int path_x[], int path_y[], int path_index, int t, int path_x_final[], int path_y_final[]);
void increment_height(int n, int X[n][n], int t);
int steps;
int min_time;

void main()
{
    int n;
    scanf("%d", &n);
    int X[n][n];
    bool visited[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n; j++)
        {
            scanf("%d", &X[i][j]);
            visited[i][j] = false;
        }
    }

    int sx, sy, fx, fy;
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    int t = 0;
    int path_index = 0;
    int path_x[50];
    int path_y[50];
    int path_x_final[50];
    int path_y_final[50];
    min_time = INT_MAX;
    print_all_paths(sx, sy, fx, fy, n, X, visited, path_x, path_y, path_index, t, path_x_final, path_y_final);

    printf("Minimum time taken is: %d", min_time);
    printf("\nThe Path to reach from (%d,%d) to (%d,%d) is: ", sx, sy, fx, fy);
    for (int i = 0 ; i < steps; i++)
    {
        printf("(%d %d) ", path_x_final[i], path_y_final[i]);
    }
    printf("\nThe Number of Blocks traversed are: %d", steps);

}

void increment_height(int n, int X[n][n], int t)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            X[i][j] = (X[i][j] > t)?(X[i][j]):t;
        }
    }
}

void print_all_paths(int sx, int sy, int fx, int fy, int n, int X[n][n], bool visited[n][n], int path_x[], int path_y[], int path_index, int t, int path_x_final[], int path_y_final[])
{
    visited[sx][sy] = true;
    path_x[path_index] = sx;
    path_y[path_index] = sy;
    path_index++;

    if ((sx == fx) && (sy == fy))
    {
        if (min_time > t)
        {
            min_time = t;
            for (int i = 0; i < path_index; i++)
            {
                path_x_final[i] = path_x[i];
                path_y_final[i] = path_y[i];
            }
            steps = path_index;
        }
    }

    else
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (((sx+i) >= 0) && ((sx+i) < n) && ((sy+j) >= 0) && ((sy+j) < n) && (i*j == 0) && visited[sx+i][sy+j] == false)
                {
                    int time = t;

                    int copy_X[n][n];
                    for (int k = 0; k < n; k++)
                    {
                        for (int l = 0; l < n; l++)
                        {
                            copy_X[k][l] = X[k][l];
                        }
                    }

                    while (copy_X[i][j] > t || copy_X[sx+i][sy+j] > t)
                    {
                        t++;
                        increment_height(n, copy_X, t);
                    }
                    print_all_paths(sx+i, sy+j, fx, fy, n, copy_X, visited, path_x, path_y, path_index, t, path_x_final, path_y_final);
                    t = time;
                }
            }
        }
    }

    path_index--;
    visited[sx][sy] = false;
}
