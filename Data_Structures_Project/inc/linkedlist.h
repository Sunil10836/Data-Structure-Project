/*
 * linkedlist.h
 *
 *  Created on: 25-Apr-2026
 *      Author: Sunil Sutar
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

extern struct Node *head;

void create(int a[], int n);
void traverse(struct Node *head);
int count(struct Node *p);

struct Node* insert_at_first(struct Node *head, int value);
struct Node* insert_at_index(struct Node *p, int index, int value);
struct Node* insert_at_last(struct Node *head, int value);

struct Node* delete_first(struct Node *head);
struct Node* delete_last(struct Node *head);
struct Node* delete_from_index(struct Node *head, int index);

int count(struct Node *p);

int menu_choice();

#endif /* LINKEDLIST_H_ */
