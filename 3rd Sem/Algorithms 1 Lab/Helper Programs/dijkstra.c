#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int min_dist(int V, int distance[], bool included[])
{
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++)
    {
        if (min >= distance[i] && included[i] == false)
        {
            min = distance[i];
            min_index = i;
        }
    }
    included[min_index] = true;
    return min_index;
}

void dijkstra(int V, int graph[][9], int src)
{
    int distance[V];//distance holds distance of src from i

    bool included[V];
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        included[i] = false;
    }

    distance[src] = 0;

    for (int i = 1; i < V; i++)
    {
        int min_index = min_dist(V, distance, included);
        for (int j = 0; j < V; j++)
        {
            if (!included[j] && graph[min_index][j] && distance[min_index] != INT_MAX && distance[min_index] + graph[min_index][j] < distance[j])
                distance[j] = distance[min_index] + graph[min_index][j];
        }
    }
    printf("Vertex  Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d       %d\n", i, distance[i]);
}

int main()
{
    int V = 9;
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(V, graph, 0);
    return 0;
}
