#include "queue.h"

//struct qnode* front = NULL;
//struct qnode* back = NULL;
/*
struct queue
{
    int* pointer;
    int* currentValue;
    int max, count, theQueue[100];
};
 */

void initQueue(struct queue *Q)
{
    Q->currentValue = malloc(sizeof(int));
    Q->pointer = Q->theQueue;
    Q->max = 100;
    Q->count = 0;
}

int pushQueue(struct queue *Q, int input)
{
    if (Q->count < Q->max)
    {
        *Q->pointer = input;
        Q->pointer++;
        Q->count++;
        return 1;
    }
    else
        return 0;
}

int* popQueue(struct queue *Q)
{
    int i;
    if (Q->count > 0)
    {

        *Q->currentValue = *Q->theQueue;
        Q->pointer--;
        Q->count--;

        for (i = 0; i < Q->count; i++)
        {
            int* currentPtr = Q->theQueue + i;
            int* nextPtr = currentPtr + 1;
            *currentPtr = *nextPtr;
        }

        return Q->currentValue;
    }
    else
        return NULL;
}

void removeduplicates(struct queue *Q)
{
    int i, j, k;
    for(i = 0; i < Q->count; i++)
    {
        for(j = 1; j < Q->count; j++)
        {
            if(Q->theQueue[j] == Q->theQueue[i])
            {
                for(k = j; k < Q->count; k++)
                {
                    Q->theQueue[k] = Q->theQueue[k+1];
                }
                Q->count--;
            }
            else
            {
                j++;
            }
        }
    }
}

void printQueue(struct queue *Q, FILE *fout)
{
    int i;
    //removeduplicates(Q);
    for(i = 0; i < Q->count; i++)
    {
        if(i >= 1)
        {
            if(Q->theQueue[i] == Q->theQueue[i-1])
            {

            }
            else
            {
                fprintf(fout, "%d\n", Q->theQueue[i]);
            }
        }
        else
        {
            fprintf(fout, "%d\n", Q->theQueue[i]);
        }
        //fprintf(fout, "%d\n", Q->theQueue[i]);
    }
}