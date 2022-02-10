# include <stdio.h>
# include <stdlib.h>
# define  QUEUE_SIZE_MAX 1000

typedef struct {
int x, y;
} POINT ;

typedef struct {
POINT *Arr ;
int queue_size, start_id, end_id;
} QUEUE;
void init(QUEUE *qP, int size);//allocates space for queue
int isempty(QUEUE *qP);//returns 1 if the queue is empty, else 0
void enqueue(QUEUE *qP, POINT *p);
POINT dequeue(QUEUE *qP);

typedef struct STACK{
POINT head;
struct STACK *next;
} STACK ;
void init_stack(STACK *s); //CHANGE THE NAMES AS C DOESN'T SUPPORT FUCNTION OVERLOADING
int isempty_stack(STACK *s);//CHANGE THE NAMES AS C DOESN'T SUPPORT FUCNTION OVERLOADING
void push(STACK *s, POINT p);
POINT pop(STACK *s);

void printgrid(int A, int B, int X_unstable[], int Y_unstable[]);
int strategy1(int A, int B, int N, int X_unstable[], int Y_unstable[], int f_x, int f_y, int j_x, int j_y, QUEUE *qP);
int bfs(int A, int B, int rocks[][B], int f_x, int f_y, int visited[][B], QUEUE* qP);

void main()
{
    //input begins
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    int X_unstable[N];
    for (int i = 0;i < N; i++)
    {
        scanf("%d", &X_unstable[i]);
    }
    int Y_unstable[N];
    for (int i = 0;i < N; i++)
    {
        scanf("%d", &Y_unstable[i]);
    }

    int j_x, j_y, f_x, f_y;
    scanf("%d %d %d %d", &j_x, &j_y, &f_x, &f_y);
    //input ends
    //part 1 begins
    printgrid(A, B, X_unstable, Y_unstable);
    //part 1 ends
    //part 2 begins
    QUEUE *qP = (QUEUE *) malloc(sizeof(QUEUE));
    init(qP, QUEUE_SIZE_MAX);
    //part 2 ends
    //part 3 starts
    int success = strategy1(A, B, N, X_unstable, Y_unstable, f_x, f_y, j_x, j_y, qP);
    //part 3 ends
    //part 4 starts
    STACK *s = (STACK *) malloc(sizeof(STACK));
    init_stack(s);
    //part 4 ends
}

void printgrid(int A, int B, int X_unstable[], int Y_unstable[])
{

    printf("Grid of stones is:\n");
    int index = 0;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if (i == X_unstable[index] && j == Y_unstable[index])
            {
                printf("_");
                index++;
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

void init(QUEUE *qP, int size)
{
    qP->queue_size = size;
    qP->start_id = 0;
    qP->end_id = -1;
    qP->Arr = (POINT *)malloc(qP->queue_size * sizeof(POINT));
}

int isempty(QUEUE *qP)
{
    if (qP->start_id > qP->end_id)
        return 1;
    return 0;
}

void enqueue(QUEUE *qP, POINT *p)
{
    qP->end_id++;

    qP->Arr[qP->end_id].x = p->x;
    qP->Arr[qP->end_id].y = p->y;
}

POINT dequeue(QUEUE *qP)
{
    int index = qP->start_id;
    qP->start_id++;
    return qP->Arr[index];
}

int strategy1(int A, int B, int N, int X_unstable[], int Y_unstable[], int f_x, int f_y, int j_x, int j_y, QUEUE *qP)
{
    int rocks[A][B];
    int index = 0;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if (i == X_unstable[index] && j == Y_unstable[index])
            {
                rocks[i][j] = 0;
                index++;
            }
            else
            {
                rocks[i][j] = 1;
            }
        }
    }

    int visited[A][B];
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            visited[i][j] = 0;
        }
    }

    POINT *start = (POINT *) malloc(sizeof(POINT));
    start->x = j_x;
    start->y = j_y;
    enqueue(qP, start);
    visited[j_x][j_y] = 1;
    int success = bfs(A, B, rocks, f_x, f_y, visited, qP);
    if (success == 1)
    {
        printf("Path Exists");
        return 1;
    }
    else if (success == 0)
    {
        printf("No Path Exists");
        return 0;
    }
}

int bfs(int A, int B, int rocks[][B], int f_x, int f_y, int visited[][B], QUEUE *qP)
{
    while(isempty(qP) != 1)
    {

        if (f_x == qP->Arr[qP->start_id].x && f_y == qP->Arr[qP->start_id].y)
        {
            return 1;
        }
        for (int i = -1; i <= 1; i+=1)
        {
            for (int j = -1; j <= 1; j+=1)
            {
                if (i*i + j*j == 2 || i*i + j*j == 0)
                {
                    continue;
                }
                int j_x = qP->Arr[qP->start_id].x;
                int j_y = qP->Arr[qP->start_id].y;
                if (j_x + i < A && j_x + i >= 0 && j_y + j < B && j_y + j >= 0)
                {
                    if (rocks[j_x+i][j_y+j] == 1 && visited[j_x + i][j_y + j] == 0)
                    {
                        POINT *start = (POINT *) malloc(sizeof(POINT));
                        start->x = j_x+i;
                        start->y = j_y+j;
                        enqueue(qP, start);
                        visited[j_x+i][j_y+j] = 1;
                    }
                }
            }
        }
        dequeue(qP);
    }
    return 0;
}

void init_stack(STACK *s)
{
    s->head.x = 0;
    s->head.y = 0;
    s->next = NULL;
}

int isempty_stack(STACK *s)
{
    if (s->next == NULL)
        return 1;
    return 0;
}

void push(STACK *s, POINT p)
{
    STACK *new_s = (STACK *) malloc(sizeof(STACK));
    new_s->next = s->next;
    new_s->head.x = p.x;
    new_s->head.y = p.y;
    s->next = new_s;
}

POINT pop(STACK *s)
{
    STACK *new_s = s->next;
    s->next = new_s->next;
    POINT p = new_s->head;
    free(new_s);
    return p;
}
