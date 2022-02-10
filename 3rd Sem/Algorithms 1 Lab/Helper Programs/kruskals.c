#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int rank;
    struct node *parent;
}
node;

typedef struct Edge
{
    int weight;
    int src;
    int dest;
}
edge;

typedef struct Graph
{
    int V;
    int E;
    edge *arr_of_edges;
    node *arr_of_vertices;
}
graph;

void merge(edge* e, int l, int m, int r);
void merge_sort(edge* e, int l, int r);
void make(int m, node C[m]);
void Union(node x, node y);
void kruskal(edge chosen_edges[], graph *g);
node *find(node *to_find);

graph *create_graph(int V, int E)
{
    graph *g = (graph*) malloc(sizeof(graph));
    g->V = V;
    g->E = E;
    g->arr_of_vertices = (node *) malloc(V*sizeof(node));
    g->arr_of_edges = (edge *) malloc(E*sizeof(edge));
    make(V, g->arr_of_vertices);
    return g;
}

void make(int m, node C[])
{
    for (int i = 0; i < m; i++)
    {
        C[i].rank = 0;
        C[i].parent = &C[i];
    }
}

node *find(node *to_find)//returns address of the top node of the tree
{
    if (to_find->parent != to_find)
    {
        to_find->parent = find(to_find->parent);
    }
    return to_find->parent;
}

void Union(node x, node y)
{
    node *addr_x = find(&x);
    node *addr_y = find(&y);

    if (addr_x->rank > addr_y->rank)
    {
        addr_y->parent = addr_x;
    }
    else if (addr_x->rank < addr_y->rank)
    {
        addr_x->parent = addr_y;
    }
    else
    {
        addr_x->parent = addr_y;
        addr_y->rank++;
    }
}

void kruskal(edge chosen_edges[], graph *g)
{
    int V = g->V;
    int E = g->E;
    int cost = 0;

    merge_sort(g->arr_of_edges, 0, E-1);
    int j = 0;
    for (int i = 0; i < E; i++)
    {
        int src = g->arr_of_edges[i].src;
        int dest = g->arr_of_edges[i].dest;
        if (find(&(g->arr_of_vertices[src])) != find(&(g->arr_of_vertices[dest])))
        {
            //take union
            Union(g->arr_of_vertices[src], g->arr_of_vertices[dest]);
            chosen_edges[j].src = src;
            chosen_edges[j].dest = dest;
            chosen_edges[j].weight = g->arr_of_edges[i].weight;
            j++;
        }
    }
}

void merge_sort(edge* e, int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        merge_sort(e, l, m);
        merge_sort(e, m + 1, r);
        merge(e, l, m, r);
    }
}


void merge(edge* e, int l, int m, int r)
{

    int i = l, j = m+1;

    int n1 = m - l + 1;
    int n2 = r - m;

    edge L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = e[l + i];
    for (j = 0; j < n2; j++)
        R[j] = e[m + 1 + j];

    i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].weight < R[j].weight)
        {
            e[k] = L[i];
            i++;
            k++;
        }
        else
        {
            e[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        e[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        e[k] = R[j];
        j++;
        k++;
    }
}
void main()
{
    int V = 4, E = 5;
    graph *g = create_graph(V, E);
    // add edge 0-1
    g->arr_of_edges[0].src = 0;
    g->arr_of_edges[0].dest = 1;
    g->arr_of_edges[0].weight = 10;

    // add edge 0-2
    g->arr_of_edges[1].src = 0;
    g->arr_of_edges[1].dest = 2;
    g->arr_of_edges[1].weight = 6;

    // add edge 0-3
    g->arr_of_edges[2].src = 0;
    g->arr_of_edges[2].dest = 3;
    g->arr_of_edges[2].weight = 5;

    // add edge 1-3
    g->arr_of_edges[3].src = 1;
    g->arr_of_edges[3].dest = 3;
    g->arr_of_edges[3].weight = 15;

    // add edge 2-3
    g->arr_of_edges[4].src = 2;
    g->arr_of_edges[4].dest = 3;
    g->arr_of_edges[4].weight = 4;

    edge chosen_edges[V-1];
    kruskal(chosen_edges, g);

    int cost = 0;
    for (int i = 0; i < V-1; i++)
    {
        printf("[%d]->[%d] (Cost) = %d\n", chosen_edges[i].src, chosen_edges[i].dest, chosen_edges[i].weight);
        cost+=chosen_edges[i].weight;
    }

    printf("Total Cost = %d", cost);
}
