/*
 * circular_queue.c
 *
 *  Created on: 26-Apr-2026
 *      Author: Sunil Sutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

void circular_queue_create(struct Circular_Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *) malloc(q->size * sizeof(int));
}

int circular_queue_isFull(struct Circular_Queue *q)
{
    if(((q->rear+1) % q->size) == q->front)
        return 1;
    else
        return 0;
}

int circular_queue_isEmpty(struct Circular_Queue *q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

void circular_queue_enqueue(struct Circular_Queue *q, int data)
{
    //Check Queue is Full
    if(circular_queue_isFull(q))
        printf("Circular_Queue is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data;   // q->Q[++q->rear] = data;
    }
}

int circular_queue_dequeue(struct Circular_Queue *q)
{
    int data = -1;

    //Check Queue is Empty
    if(circular_queue_isEmpty(q))
        printf("Circular_Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        data = q->Q[q->front];
    }
    return data;
}

void circular_queue_traverse(struct Circular_Queue *q)
{
    int i = q->front+1;

    do
    {
        printf("%d ", q->Q[i]);
        i = (i+1) % q->size;

    } while(i != (q->rear+1) % q->size);

    printf("\n");
}
