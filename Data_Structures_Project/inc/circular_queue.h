/*
 * circular_queue.h
 *
 *  Created on: 26-Apr-2026
 *      Author: Sunil Sutar
 */

#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

struct Circular_Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void circular_queue_create(struct Circular_Queue *q, int size);

void circular_queue_enqueue(struct Circular_Queue *q, int data);
int circular_queue_dequeue(struct Circular_Queue *q);
void circular_queue_traverse(struct Circular_Queue *q);

int circular_queue_isFull(struct Circular_Queue *q);
int circular_queue_isEmpty(struct Circular_Queue *q);

#endif /* CIRCULAR_QUEUE_H_ */
