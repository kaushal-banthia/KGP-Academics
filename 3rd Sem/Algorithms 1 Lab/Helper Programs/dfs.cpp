#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    int e;
    int **adj;

public:
    Graph(int v, int e);
    void addEdge(int start, int e);
    void DFS(int start, bool visited[]);
};

Graph::Graph(int v, int e)
{
    adj = new int*[v];
    for (int row = 0; row < v; row++)
    {
        adj[row] = new int[v];
        for (int column = 0; column < v; column++)
        {
            adj[row][column] = 0;
        }
    }
}

void Graph::addEdge(int start, int e)
{
    adj[start][e] = 1;
    adj[e][start] = 1;
}

void Graph::DFS(int start, bool visited[])
{
    //print the current node
    cout<<start<<" ";
    //set current node as visited
    visited[start] = true;
    //for every node in the graph
    for (int i = start; i < v; i++)
    {
        if (adj[start][i] == 1 && visited[i] == true)
        {
            cout<<"\nCycle detected\n";
        }
        if (adj[start][i] == 1 && visited[i] == false)
        {
            DFS(i, visited);
        }
    }
}

int main()
{
    int v = 4, e = 4;
    Graph G(v, e);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 2);
    G.addEdge(0, 1);

    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    G.DFS(0, visited);
}
