/*
 * linkedlist.c
 *
 *  Created on: 25-Apr-2026
 *      Author: Sunil Sutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void create(int a[], int n)
{
    int i;
    struct Node *temp, *last;
    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = a[0];
    head->next = NULL;
    last = head;

    for(i=1; i<n ;i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void traverse(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int count=0;

    while (p != 0)
    {
        count++;
        p = p->next;
    }
    return count;
}

struct Node* insert_at_first(struct Node *head, int value)
{
    //create new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

struct Node* insert_at_index(struct Node *p, int index, int value)
{
    int i;

    struct Node *temp;
    if(index < 0 || index > count(p))
        return NULL;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;

    //Insert at begining
    if(index == 0)
    {
        //p = head;
        temp->next = head;
        head = temp;
    }
    else if(index > 0)
    {
        p = head;
        for(i = 0; i<index-1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return temp;
}

struct Node* insert_at_last(struct Node *head, int value)
{
    struct Node *p = head;

    //Creating New Node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //Traverse till last node
    while (p->next != NULL)
    {
        p = p->next;
    }

    //insert new node at last
    p->next = newNode;

    return head;
}

struct Node* delete_first(struct Node *head)
{
    int data=-1;
    if(head==NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    struct Node *p = head;
    data = head->data;
    printf("Deleted Node Data = %d\n", data);
    head = head->next;
    free(p);
    return head;
}

struct Node* delete_last(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = NULL;
    int data = -1;

    if(head==NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    //if List has only one node
    if(head->next == NULL)
    {
        free(head);
        head=NULL;
        return NULL;
    }

    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    data = p->data;
    printf("Deleted Node Data = %d\n", data);
    q->next = NULL;
    free(p);
    return head;
}

struct Node* delete_from_index(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = NULL;

    // Case 1: Empty list
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Delete first node
    if (index == 0)
    {
        head = p->next;
        printf("Deleted %d from index %d\n", p->data, index);
        free(p);
        return head;
    }

    for(int i=0; i<index; i++)
    {
        q = p;
        p = p->next;

         // Check if index is out of bounds
        if (p == NULL)
        {
            printf("Index out of range\n");
            return head;
        }
    }

    q->next = p->next;
    printf("Deleted %d from %d index\n", p->data, index);
    free(p);
    return head;
}
