/*
 * stack.h
 *
 *  Created on: 25-Apr-2026
 *      Author: Sunil Sutar
 */

#ifndef STACK_H_
#define STACK_H_

struct Stack
{
    int size;
    int top;
    int *S;
};

void stack_create(struct Stack *st);
void stack_traverse(struct Stack st);

int isFull(struct Stack *st);
int isEmpty(struct Stack *st);

void push(struct Stack *st, int data);
int pop(struct Stack *st);

int peek(struct Stack st, int index);
int stackTop(struct Stack st);


#endif /* STACK_H_ */
