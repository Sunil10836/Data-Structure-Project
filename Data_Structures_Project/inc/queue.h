/*
 * queue.h
 *
 *  Created on: 26-Apr-2026
 *      Author: Sunil Sutar
 */

#ifndef QUEUE_H_
#define QUEUE_H_

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void queue_create(struct Queue *q, int size);

void queue_enqueue(struct Queue *q, int data);
int queue_dequeue(struct Queue *q);
void queue_traverse(struct Queue *q);

int queue_isFull(struct Queue *q);
int queue_isEmpty(struct Queue *q);

#endif /* QUEUE_H_ */
