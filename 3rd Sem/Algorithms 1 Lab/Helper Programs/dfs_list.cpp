#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node * next;
}
node;

typedef struct Graph
{
    int v;
    bool *visited;
    node **lists;
}
Graph;

node *create_node(int v)
{
    node *newnode = (node *) malloc(sizeof(node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

Graph *create_graph(int v)
{
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->v = v;
    graph->lists = (node **) malloc(sizeof(node*));
    graph->visited = (bool *) malloc(sizeof(bool));

    for (int i = 0; i < v; i++)
    {
        graph->visited[i] = false;
        graph->lists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    node* newNode = create_node(dest);
    newNode->next = graph->lists[src];
    graph->lists[src] = newNode;

    // Add edge from dest to src
    newNode = create_node(src);
    newNode->next = graph->lists[dest];
    graph->lists[dest] = newNode;
}

void print(Graph *graph)
{
    for (int v = 0; v < graph->v; v++)
    {
        node *temp = graph->lists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while(temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfs(Graph *graph, int start)
{
    node *newlist = graph->lists[start];
    node *temp = newlist;
    graph->visited[start] = true;
    printf("Visited %d \n", start);

    while (temp)
    {
        int neighbour = temp->vertex;
        if (graph->visited[neighbour] == false)
        {
            dfs(graph, neighbour);
        }
        temp = temp->next;
    }
}

int main()
{
    Graph *graph = create_graph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    print(graph);

    dfs(graph, 2);

    return 0;
}
