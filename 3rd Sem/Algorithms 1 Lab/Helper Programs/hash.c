#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int key;
    int value;
    int flag; //0 means Empty; 1 means Element Present; 2 means skippable;
}
item;

void insert(int key, item *arr, int value);
void del(int key, item *arr);
int find(int key, item *arr);

int hash(int key, int i)
{
    return ((key%100 + i*(7-key%7)))%100;
}

void main()
{
    item *arr = (item *) malloc(100*sizeof(item));
    for (int i = 0; i < 100; i++)
    {
        arr[i].flag = 0;
    }
    insert(2, arr, 27);
    insert(8, arr, 78);
    insert(10, arr, 90);
    del(8, arr);


    int index = find(10, arr);
    if (index != -1)
    {
        printf("Element value: %d, found at key: %d", arr[index].value, arr[index].key);
    }
}

void insert(int key, item *arr, int value)
{
    int i = 0;
    int index = hash(key, i);
    while (arr[index].flag == 1 && i < 100)
    {
        if (arr[index].key == key)
        {
            arr[index].value = value;
            return;
        }

        i++;
        index = hash(key, i);
    }
    if (i==100)
    {
        printf("Hash Table is Full\n");
        return;
    }
    arr[index].flag = 1;
    arr[index].value = value;
    arr[index].key = key;
    printf("Element Added\n");
}

void del(int key, item *arr)
{
    int index = find(key, arr);
    if (index == -1)
    {
        printf("No such element could be deleted\n");
        return;
    }

    arr[index].flag = 2;
    printf("Element Deleted\n");
}

int find(int key, item *arr)
{
    int i = 0;
    int index = hash(key, i);
    while (arr[index].flag != 0 && arr[index].key != key && i < 100)
    {
        i++;
        index = hash(key, i);
    }
    if (i == 100 || arr[index].key != key || arr[index].flag == 0 || arr[index].flag == 2)
    {
        printf("No such key present\n");
        return -1;
    }
    return index;
}
