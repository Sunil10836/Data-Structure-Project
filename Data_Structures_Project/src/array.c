/*
 * array.c
 *
 *  Created on: 27-Apr-2026
 *      Author: Sunil Sutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//struct Array *arr = NULL;

void array_create(struct Array *arr, int size)
{
    //printf("Enter size = ");
    //scanf("%d", &arr->size);
	arr->lenth = 0;
	arr->size = size;
    arr->A = (int *) malloc(arr->size * sizeof(int));

}

void array_traverse(struct Array *arr)
{
    int i;
    printf("Array Elements are : \n");
    for(i=0; i<arr->lenth; i++)
    {
        printf("%d ", arr->A[i]);
    }
}

void array_append(struct Array *arr, int data)
{
    if(arr->lenth < arr->size)
    {
        arr->A[arr->lenth] = data;
        arr->lenth++;
    }
}

void array_insert_at_index(struct Array *arr, int index, int data)
{
    if(index >= 0 && index <= arr->lenth)
    {
        for(int i=arr->lenth; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = data;
        arr->lenth++;
    }
}

int array_delete(struct Array *arr, int index)
{
    int data = -1;
    if(index >= 0 && index <= arr->lenth)
    {
        data = arr->A[index];

        for(int i=index; i<arr->lenth-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->lenth--;
    }
    return data;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0; i<arr->lenth; i++)
    {
        if(key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr->lenth-1;

    while (low <= high)
    {
        mid = (low + high)/2;

        if(key == arr->A[mid])
            return mid;
        else if(key < arr->A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Max(struct Array *arr)
{
    int max = arr->A[0];
    int i;
    for(i=0; i<arr->lenth; i++)
    {
        if(arr->A[i] > max)
            max = arr->A[i];
    }
    return max;
}

int Min(struct Array *arr)
{
    int min = arr->A[0];
    int i;
    for(i=0; i<arr->lenth; i++)
    {
        if(arr->A[i] < min)
            min = arr->A[i];
    }
    return min;
}

int Sum(struct Array *arr)
{
    int sum = 0;
    int i;
    for(i=0; i<arr->lenth; i++)
    {
        sum += arr->A[i];
    }
    return sum;
}

float Avg(struct Array *arr)
{
    return (float) (Sum(arr) / arr->lenth);
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void array_reverse(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->lenth-1;

    while (i < j)
    {
       swap(&arr->A[i], &arr->A[j]);
       i++;
       j--;
    }
}