//
// Created by Tyler on 10/16/2016.
//

#ifndef CIS361PROJECT2_QUEUE_H
#define CIS361PROJECT2_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int* pointer;
    int* currentValue;
    int max, count, theQueue[100];
};

void initQueue(struct queue* Q);
int pushQueue(struct queue* Q, int input);
int* popQueue(struct queue* Q);
void printQueue(struct queue *Q, FILE *fout);
void removeduplicates(struct queue *Q);

#endif //CIS361PROJECT2_QUEUE_H
