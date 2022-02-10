#include <stdio.h>
#include <stdlib.h>

void min_heapify(int i, int heap[], int heap_size);

void insert_key(int key, int cap, int *heap_size, int heap[])
{
    if (*heap_size == cap)
        printf("Limit Reached. Cannot input more elements in the heap");
    else
    {
        int loc = *heap_size;
        (*heap_size)++;
        heap[loc] = key;
        for (int i = loc; i != 0 && heap[(i-1)/2] > heap[i]; i--)
        {
            int temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = heap[i];
        }
    }
}

void delete_min(int heap[], int *heap_size)
{
    if (*heap_size == 0)
        printf("No element to delete");
    else if (*(heap_size) == 1)
    {
        printf("%d", heap[0]);
        (*heap_size)--;
    }
    else
    {

        (*heap_size)--;
        int root = heap[0];
        heap[0] = heap[*heap_size];
        printf("%d", root);
        min_heapify(0, heap, *heap_size);
    }
}

int find_min(int heap[], int heap_size)
{
    if (heap_size == 0)
    {
        printf("No element in heap");
        return -1;
    }
    return heap[0];
}

void min_heapify(int i, int heap[], int heap_size)
{
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    int smallest = i;
    if (left_child < heap_size && heap[left_child] < heap[i])
        smallest = left_child;
    if (right_child < heap_size && heap[right_child] < heap[smallest])
        smallest = right_child;
    if (smallest != i)
    {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        min_heapify(smallest, heap, heap_size);
    }
}

void heapify(int heap[], int heap_size)
{
    int start = heap_size/2 - 1;
    for (int i = start; i >= 0; i--)
        min_heapify(i, heap, heap_size);
}

void main()
{
    int heap_size = 11;
    int heap[11] = {16, 3, 5, 4, 6, 1, 10, 9, 8, 15, 17};
    heapify(heap, heap_size);
    delete_min(heap, &heap_size);
    printf(" %d", find_min(heap, heap_size));

}

