#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int height;
    struct node *parent;
}
node;

void makeset(node arr[], int n);
node *find(node *to_find);//returns address of the top node of the tree
void Union(node a, node b);

void main()
{
    int n = 5;
    node arr[n];

    makeset(arr, n);

    Union(arr[0], arr[1]);
    Union(arr[1], arr[2]);
    Union(arr[2], arr[3]);

    if (find(&arr[2]) == find(&arr[4]))
        printf("Yes");
    else
        printf("False");

}

void makeset(node arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].value = i;
        arr[i].height = 0;
        arr[i].parent = &arr[i];
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

void Union(node a, node b)
{
    node *addr_a = find(&a);
    node *addr_b = find(&b);

    if (addr_a->height > addr_b->height)
    {
        addr_b->parent = addr_a;
    }
    else if (addr_a->height < addr_b->height)
    {
        addr_a->parent = addr_b;
    }
    else
    {
        addr_b->parent = addr_a;
        addr_a->height++;
    }
}
