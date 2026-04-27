/*
 * array.h
 *
 *  Created on: 27-Apr-2026
 *      Author: Sunil Sutar
 */

#ifndef ARRAY_H_
#define ARRAY_H_

struct Array
{
    int *A;         //pointer to an array
    int size;       //total size
    int lenth;      //lenth of array
};

extern struct Array *arr;

void array_create(struct Array *arr, int size);
//void array_create(struct Array *arr);
void array_traverse(struct Array *arr);

void array_append(struct Array *arr, int data);
void array_insert_at_index(struct Array *arr, int index, int data);
int array_delete(struct Array *arr, int index);

void swap(int *x, int *y);
void array_reverse(struct Array *arr);

int LinearSearch(struct Array *arr, int key);
int BinarySearch(struct Array *arr, int key);

int Max(struct Array *arr);
int Min(struct Array *arr);

int Sum(struct Array *arr);
float Avg(struct Array *arr);

#endif /* ARRAY_H_ */
