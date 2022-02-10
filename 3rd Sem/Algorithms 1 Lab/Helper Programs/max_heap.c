#include <stdio.h>
#include <stdlib.h>

void max_heapify(int i, int heap[], int heap_size);

void insert_key(int key, int cap, int *heap_size, int heap[])
{
    if (*heap_size == cap)
        printf("Limit Reached. Cannot input more elements in the heap");
    else
    {
        int loc = *heap_size;
        (*heap_size)++;
        heap[loc] = key;
        for (int i = loc; i != 0 && heap[(i-1)/2] < heap[i]; i--)
        {
            int temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = temp;
        }
    }
}

void delete_max(int heap[], int *heap_size)
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
        max_heapify(0, heap, *heap_size);
    }
}

int find_max(int heap[], int heap_size)
{
    if (heap_size == 0)
    {
        printf("No element in heap");
        return -1;
    }
    return heap[0];
}

void max_heapify(int i, int heap[], int heap_size)
{
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    int largest = i;
    if (left_child < heap_size && heap[left_child] > heap[i])
        largest = left_child;
    if (right_child < heap_size && heap[right_child] > heap[largest])
        largest = right_child;
    if (largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        max_heapify(largest, heap, heap_size);
    }
}

void heapify(int heap[], int heap_size)
{
    int start = heap_size/2 - 1;
    for (int i = start; i >= 0; i--)
        max_heapify(i, heap, heap_size);
}

void main()
{
    int heap[100];
    int heap_size = 0;
    insert_key(3, 100, &heap_size, heap);
    insert_key(7, 100, &heap_size, heap);
    insert_key(100, 100, &heap_size, heap);
    insert_key(2, 100, &heap_size, heap);
    insert_key(56, 100, &heap_size, heap);

    /*int heap[11] = {16, 3, 5, 4, 6, 1, 100, 9, 8, 15, 17};
    int heap_size = 11;*/
    heapify(heap, heap_size);
    delete_max(heap, &heap_size);
    printf(" %d", find_max(heap, heap_size));
}
