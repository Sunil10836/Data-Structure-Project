/*
 * stack.c
 *
 *  Created on: 25-Apr-2026
 *      Author: Sunil Sutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_create(struct Stack *st)
{
    printf("Enter Size = ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *) malloc(st->size * sizeof(int));
}

void stack_traverse(struct Stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

int isFull(struct Stack *st)
{
    if(st->top == st->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, int data)
{
    if(isFull(st))
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = data;
    }
}

int pop(struct Stack *st)
{
    int data = -1;

    if(isEmpty(st))
        printf("Stack Underflow\n");
    else
    {
        data = st->S[st->top];
        st->top--;
    }
    return data;
}

int peek(struct Stack st, int index)
{
    int data = -1;
    if(st.top-index+1 < 0)
        printf("Invalid Index\n");
    data = st.S[st.top-index+1];
    return data;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(&st))
        return st.S[st.top];
    return -1;
}

