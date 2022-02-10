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
    void BFS(int start);
};


//queue
typedef struct node
{
    int num;
    struct node *next;
}
node;

int ex = 0;
int coun = 0;
node *enque(node *head, int x);
node *dequeue(node **head);
int fronts(node *head);

node* enque(node *head, int x)
{
		node *newnode = (node *) malloc(sizeof(node));

		if (newnode == NULL)
		{
			return head;
		}
		newnode->num = x;
		newnode->next = head;
		coun++;
		return newnode;
}

node *dequeue(node **head)
{
	if (coun == 0)
	{
		return *head;
	}
	node *addr = *head, *prev;
	while (addr->next != NULL)
	{
		prev = addr;
		addr = addr->next;
	}
    coun--;
    if (coun == 0)
    {
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
    }


	return(*head);
}

int fronts(node *head)
{
	if (coun == 0)
	{
		return -1;
	}
	node *addr = head;
	while(addr->next != NULL)
	{
		addr = addr->next;
	}
	return addr->num;
}

//queue ends

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

void Graph::BFS(int start)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    node *head = NULL;
    head = enque(head, start);
    //set current node as visited
    visited[start] = true;

    int vis;
    while(coun!=0)
    {
        vis = fronts(head);
        if (vis == 4)
        {
            cout<<vis;
            break;
        }
        cout<<vis<<" ";
        head = dequeue(&head);


        for (int i = 0; i < v; i++)
        {
            if (adj[vis][i] == 1 && visited[i] == false)
            {
                head = enque(head, i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v = 8, e = 7;
    Graph G(v, e);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(4, 1);
    G.addEdge(5, 1);
    G.addEdge(2, 7);
    G.addEdge(3, 6);
    G.BFS(0);
}
