/*
 * queue.c
 *
 *  Created on: 26-Apr-2026
 *      Author: Sunil Sutar
 */


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queue_create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *) malloc(q->size * sizeof(int));
}

int queue_isFull(struct Queue *q)
{
    if(q->rear == q->size-1)
        return 1;
    else
        return 0;
}

int queue_isEmpty(struct Queue *q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

void queue_enqueue(struct Queue *q, int data)
{
    //Check Queue is Full
    if(queue_isFull(q))
        printf("Queue is Full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = data;   // q->Q[++q->rear] = data;
    }
}

void queue_traverse(struct Queue *q)
{
    for(int i=q->front+1; i<=q->rear; i++)
    {
        printf("%d ", q->Q[i]);
    }
    printf("\n");
}

int queue_dequeue(struct Queue *q)
{
    int data = -1;

    //Check Queue is Empty
    if(queue_isEmpty(q))
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        data = q->Q[q->front];
    }
    return data;
}

