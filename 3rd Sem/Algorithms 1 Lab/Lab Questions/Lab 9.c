#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct _job {
int jobId;
int startTime;
int jobLength;
int remLength;
} job;
typedef struct _heap {
job jobList[MAX_SIZE];
int numJobs;
} heap;

void initHeap(heap *H);
void insertJob(heap *H, job j);
int extractMinJob(heap *H, job *j);
void scheduler(job jobList[], int n);
void min_heapify(int i, heap *H);
void count_sort(job *List, int max_start_time, int n, job *jobList);

int main()
{
    int n;
    scanf("%d", &n);
    job *jobList = (job *) malloc(n*sizeof(job));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &(jobList[i].jobId), &(jobList[i].startTime), &(jobList[i].jobLength));
        jobList[i].remLength = jobList[i].jobLength;
    }
    scheduler(jobList, n);
    return 0;
}

void scheduler(job jobList[], int n)
{
    heap *H = (heap *) malloc(sizeof(heap));
    initHeap(H);
    H->numJobs = 0;

    int maximum_start_time = 0;
    int total_time = 0;
    for (int i = 0; i < n; i++)
    {
        maximum_start_time = maximum_start_time>jobList[i].startTime?maximum_start_time:jobList[i].startTime;
        total_time +=jobList[i].jobLength;
    }

    job *List = (job *) malloc(n*sizeof(job));
    count_sort(List, maximum_start_time, n, jobList);

    //printf("list[0].remLength = %d\n",List[0].remLength);
    int i = 0;
    for (int t = 0; t < total_time; t++)
    {
        //printf("t = %d\n\n",t);
        while(1)
        {
            if (i < n && List[i].startTime == t)
            {
                //printf("i = %d\n",i);
                insertJob(H, List[i]);
                i++;
            }
            else
                break;
        }



        job *j = (job *) malloc(sizeof(job));
        extractMinJob(H, j);

        printf("%d ", j->jobId);
        //printf("job rem = %d\n",j->remLength);
        (j->remLength)--;
        if ((j->remLength) > 0)
            insertJob(H, *j);

        free(j);
    }
}

void initHeap(heap *H)
{
    H->numJobs = 0;
}

void insertJob(heap *H, job j)
{
    if (H->numJobs == MAX_SIZE)
        printf("Limit Reached. Cannot input more elements in the heap");
    else
    {
        int loc = H->numJobs;
        //printf("Inserting Node = %d\n",j.jobId);
        //printf("numjobs befor increment = %d\n",H->numJobs);
        (H->numJobs)++;
        //printf("numjobs after increment = %d\n",H->numJobs);
        (H->jobList[loc]).jobId = j.jobId;
        (H->jobList[loc]).jobLength = j.jobLength;
        if (j.jobLength > j.remLength)
            (H->jobList[loc]).remLength = j.remLength;
        else
            (H->jobList[loc]).remLength = j.jobLength;
        (H->jobList[loc]).startTime = j.startTime;

        for (int i = loc; i != 0 && (H->jobList[(i-1)/2]).remLength > (H->jobList[i]).remLength; i--)
        {
            job temp;
            temp.jobId = H->jobList[(i-1)/2].jobId;
            temp.jobLength = H->jobList[(i-1)/2].jobLength;
            temp.remLength = H->jobList[(i-1)/2].remLength;
            temp.startTime = H->jobList[(i-1)/2].startTime;

            H->jobList[(i-1)/2].jobId= H->jobList[i].jobId;
            H->jobList[(i-1)/2].jobLength= H->jobList[i].jobLength;
            H->jobList[(i-1)/2].remLength= H->jobList[i].remLength;
            H->jobList[(i-1)/2].startTime= H->jobList[i].startTime;

            H->jobList[i].jobId = temp.jobId;
            H->jobList[i].jobLength = temp.jobLength;
            H->jobList[i].remLength = temp.remLength;
            H->jobList[i].startTime = temp.startTime;
        }
    }
}

int extractMinJob(heap *H, job *j)
{
    if (H->numJobs == 0)
    {
        return -1;
    }

    else
    {
        j->jobId = H->jobList[0].jobId;
        j->jobLength = H->jobList[0].jobLength;
        j->remLength = H->jobList[0].remLength;
        j->startTime= H->jobList[0].startTime;

        (H->numJobs)--;
        H->jobList[0].jobId = H->jobList[H->numJobs].jobId;
        H->jobList[0].jobLength = H->jobList[H->numJobs].jobLength;
        H->jobList[0].remLength = H->jobList[H->numJobs].remLength;
        H->jobList[0].startTime = H->jobList[H->numJobs].startTime;

        min_heapify(0, H);
        return 0;
    }
}

void min_heapify(int i, heap *H)
{
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    int smallest = i;
    if (left_child < H->numJobs && (H->jobList[left_child]).remLength < (H->jobList[smallest]).remLength)
        smallest = left_child;
    if (right_child < H->numJobs && (H->jobList[right_child]).remLength < (H->jobList[smallest]).remLength)
        smallest = right_child;
    if (smallest != i)
    {
        job temp;
        temp.jobId = H->jobList[i].jobId;
        temp.jobLength = H->jobList[i].jobLength;
        temp.remLength = H->jobList[i].remLength;
        temp.startTime = H->jobList[i].startTime;

        H->jobList[i].jobId = H->jobList[smallest].jobId;
        H->jobList[i].jobLength = H->jobList[smallest].jobLength;
        H->jobList[i].remLength = H->jobList[smallest].remLength;
        H->jobList[i].startTime = H->jobList[smallest].startTime;

        H->jobList[smallest].jobId = temp.jobId;
        H->jobList[smallest].jobLength = temp.jobLength;
        H->jobList[smallest].remLength = temp.remLength;
        H->jobList[smallest].startTime = temp.startTime;

        min_heapify(smallest, H);
    }
}

void count_sort(job *List, int max_start_time, int n, job *jobList)
{
    int count[max_start_time + 1], i;
    for (int j = 0; j < max_start_time+1; j++)
    {
        count[j] = 0;
    }

    for (i = 0; i < n; i++)
        count[jobList[i].startTime]++;

    for (i = 1; i <= max_start_time; ++i)
        count[i] += count[i - 1];

     for (i = 0; i < n; i++)
    {
        List[count[jobList[i].startTime]-1].jobId = jobList[i].jobId;
        List[count[jobList[i].startTime]-1].jobLength = jobList[i].jobLength;
        List[count[jobList[i].startTime]-1].remLength = jobList[i].remLength;
        List[count[jobList[i].startTime]-1].startTime = jobList[i].startTime;

        count[jobList[i].startTime]--;
    }

}
