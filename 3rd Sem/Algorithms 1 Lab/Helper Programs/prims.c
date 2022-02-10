#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int minKey(int V, int key[V], bool mstSet[V]);
void primMST(int V, int graph[V][V]);

void main()
{
    int V = 5;
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(V, graph);
}

void primMST(int V, int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V-1; i++)
    {
        int u = minKey(V, key, mstSet);
        mstSet[i] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j])
                parent[j] = u, key[j] = graph[u][j];
        }
    }

    printMST(V, parent, graph);
}

int minKey(int V, int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void printMST(int V, int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


/*  2    3
(0)--(1)--(2)
 |   / \   |
6| 8/   \5 |7
 | /     \ |
(3)-------(4)
       9
*/
