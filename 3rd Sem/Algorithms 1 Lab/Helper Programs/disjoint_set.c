// C++ implementation of disjoint set
#include <stdio.h>
#include <stdlib.h>

void makeset(int parent[], int arr[], int n, int rank[]);
void Union(int x, int y, int rank[], int parent[]);
int find(int x, int parent[]);

void main()
{
    int n = 5;
    int arr[5] = {0, 1, 2, 3, 4};
    int parent[100];
    int rank[100];
    makeset(parent, arr, n, rank);

    Union(0, 2, rank, parent);
    Union(4, 2, rank, parent);
    Union(3, 1, rank, parent);
    if (find(4, parent) == find(2, parent))
        printf("Yes\n");
    else
        printf("No\n");
    if (find(2, parent) == find(3, parent))
        printf("Yes\n");
    else
        printf("No\n");
}

void makeset(int parent[], int arr[], int n, int rank[])
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = arr[i];
        rank[i] = 0;
    }
}

int find(int x, int parent[])
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x], parent);
    }

    return parent[x];//returns the x who is at the top of the tree for the original x
}

void Union(int x, int y, int rank[], int parent[])
{
    int xset = find(x, parent);
    int yset = find(y, parent);

    if (rank[xset] > rank[yset])
        parent[yset] = xset;
    else if (rank[yset] > rank[xset])
        parent[xset] = yset;
    else
    {
        parent[xset] = yset;
        rank[yset]++;
    }
}

