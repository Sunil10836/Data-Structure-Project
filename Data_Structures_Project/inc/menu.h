/*
 * menu.h
 *
 *  Created on: 25-Apr-2026
 *      Author: Sunil Sutar
 */

#ifndef MENU_H_
#define MENU_H_

#include "linkedlist.h"
#include "array.h"

typedef enum
{
    STACK_PUSH=1,
    STACK_POP,
    STACK_PEEK,
    STACK_TOP,
	STACK_BACK
}StackMenu_t;

typedef enum
{
	QUEUE_ENQUEUE=1,
	QUEUE_DEQUEUE,
	QUEUE_TRAVERSE,
	QUEUE_BACK
}QueueMenu_t;

typedef enum
{
	CIR_QUEUE_ENQUEUE=1,
	CIR_QUEUE_DEQUEUE,
	CIR_QUEUE_TRAVERSE,
	CIR_QUEUE_BACK

}CircularQueueMenu_t;

void array_test();
void linked_list_test(struct Node *);
void stack_test();
void queue_test();
void circular_queue_test();

int array_menu_choice();
int linked_list_menu_choice();
int stack_menu_choice();
int queue_menu_choice();
int circular_queue_menu_choice();

#endif /* MENU_H_ */
