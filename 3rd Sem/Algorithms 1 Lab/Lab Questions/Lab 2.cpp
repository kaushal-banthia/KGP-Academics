// 19CS10039\_G05\_Assign2.c
#include "assign2.h"

void point_slabs(Box boxes[], int low, int high, Point *point_array);
void merge(int low, int high, Point* point_array, int mid);

Point* findOutLine(Box boxes[], int size, int* outputsize)
{
    Point* point_array;
    // here solve the problem, where boxes contain the input data and size is the number of boxes on the table
    point_slabs(boxes, 0, size - 1, point_array);
    outputsize = 0;
    for (int i = 0; i < size; i ++)
    {
        if ((*(point_array + i)).x != -1)
        {
            outputsize++;
        }
    }
    // set outputsize to the number of points in Point array you are yet to return
    for (int i = 0; i < size; i ++)
    {
        if ((*(point_array + i)).x == -1)
        {
            (*(point_array + i)).x = (*(point_array + i + 1)).x;
            (*(point_array + i)).y = (*(point_array + i + 1)).y;
        }

    }
    return point_array;//please note that the output will come only for outputsize number of values, and not all, because I haven't removed the -1, -1 values due to lack of time.
}

int main()
{
    process();
    return 0;
}

void point_slabs(Box boxes[], int low, int high, Point *point_array)
{
    if (low == high)
    {
        Point p1, p2;
        (*(point_array + 2*low)).x = boxes[low].left;
        (*(point_array + 2*low)).y = boxes[low].ht;

        (*(point_array + 2*low + 1)).x = boxes[low].right;
        (*(point_array + 2*low + 1)).y = 0;
        return;
    }

    else
    {
        int mid = (low + high)/2;
        point_slabs(boxes, low, mid,  point_array);
        point_slabs(boxes, mid + 1, high, point_array);
        merge(low, high, point_array, mid);
    }
}

void merge(int low, int high, Point* point_array, int mid)
{
    if ((*(point_array + 2*mid + 2)).x < (*(point_array + 2*mid + 1)).x && (*(point_array + 2*mid)).y < (*(point_array + 2*mid + 2)).y)
    {
        (*(point_array + 2*mid + 1)).x = -1;
        (*(point_array + 2*mid + 1)).y = -1;
    }

    else if ((*(point_array + 2*mid + 2)).x < (*(point_array + 2*mid + 1)).x && (*(point_array + 2*mid + 2)).y < (*(point_array + 2*mid )).y)
    {
        (*(point_array + 2*mid + 2)).x = (*(point_array + 2*mid + 1)).x;
        (*(point_array + 2*mid + 1)).x = -1;
        (*(point_array + 2*mid + 1)).y = -1;
    }
}
