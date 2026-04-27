/*
 * menu.c
 *
 *  Created on: 25-Apr-2026
 *      Author: Sunil Sutar
 */

#include "menu.h"
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include "circular_queue.h"
#include "array.h"

//struct Array *arr = NULL;

void array_test()
{
    int data, size, index, key, choice = 0;
    struct Array arr;

    do
    {
        choice = array_menu_choice();

        switch (choice)
        {
            case 1:
            	printf("Enter Array Size = ");
            	scanf("%d", &size);
            	array_create(&arr, size);
                printf("Enter array Elements \n");
                for(int i=0; i<arr.size; i++)
                {
                    printf("Enter Data %d = ", i);
                    scanf("%d", &data);
                    array_append(&arr, data);
                }
                printf("\n");
                array_traverse(&arr);
                break;

            case 2:
                printf("Enter Index = ");
                scanf("%d", &index);
                printf("Enter Data = ");
                scanf("%d", &data);
                array_insert_at_index(&arr, index, data);
                array_traverse(&arr);
                break;

            case 3:
                printf("Enter Index = ");
                scanf("%d", &index);
                printf("Deleted = %d\n", array_delete(&arr, index));
                array_traverse(&arr);
                break;

            case 4:
                printf("Enter Key = ");
                scanf("%d", &key);
                printf("Key Found at %d index", LinearSearch(&arr, key));
                break;

            case 5:
                printf("Enter Key = ");
                scanf("%d", &key);
                printf("Key Found at index : %d ", BinarySearch(&arr, key));
                break;

            case 6:
                printf("Max Element = %d\n", Max(&arr));
                break;

            case 7:
                printf("Min Element = %d\n", Min(&arr));
                break;

            case 8:
                printf("Sum = %d\n", Sum(&arr));
                break;

            case 9:
                printf("Avg = %.2f\n", Avg(&arr));
                break;

            case 10:
            	array_reverse(&arr);
            	array_traverse(&arr);
                break;

            case 11:
            	return;
            	break;

            default:
                printf("Invalid Choice\n");
                break;
        }

    } while (choice != 0);

}

void linked_list_test(struct Node *head)
{
    int value, index;
    int a[] = {10, 20, 30};
    int choice;

    do
    {
        choice = linked_list_menu_choice();

        switch (choice)
        {
            case 1:
                create(a, 3);
                traverse(head);
            break;

            case 2:
                printf("Enter Value = ");
                scanf("%d", &value);
                head = insert_at_first(head, value);
                traverse(head);
            break;

            case 3:
                printf("Enter Index = ");
                scanf("%d", &index);
                printf("Enter Value = ");
                scanf("%d", &value);
                if(index <= count(head)) {
                    head = insert_at_index(head, index, value);
                    traverse(head);
                }
                else {
                    printf("Invalid Index\n");
                }
            break;

            case 4:
                printf("Enter Value = ");
                scanf("%d", &value);
                head = insert_at_last(head, value);
                traverse(head);
            break;

            case 5:
                head = delete_first(head);
                traverse(head);
            break;

            case 6:
                printf("Enter Index = ");
                scanf("%d", &index);
                head = delete_from_index(head, index);
                traverse(head);
            break;

            case 7:
                head = delete_last(head);
                traverse(head);
            break;

            case 8: //count Nodes
                printf("Count = %d\n", count(head));
            break;

            case 9:
            	return;
            	break;

            default:
                printf("Invalid Choice\n");
                break;
        }

    } while (choice != 0);

    return;
}

void stack_test()
{
    int choice;
    struct Stack st;
    int index=0;
    int data=0;

    do
    {
        choice = stack_menu_choice();

		switch(choice)
		{
			case STACK_PUSH:
				stack_create(&st);
				for(int i=1; i<=st.size; i++)
				{
					printf("Enter Data = ");
					scanf("%d", &data);
					push(&st, data);
				}
				stack_traverse(st);
			break;
			case STACK_POP:
				printf("poped = %d\n", pop(&st));
				stack_traverse(st);
			break;

			case STACK_PEEK:
				printf("Enter Index = ");
				scanf("%d", &index);
				printf("Data at index %d  = %d\n", index, peek(st, index));
			break;

			case STACK_TOP:
				printf("Top Element = %d\n", stackTop(st));
			break;

			case STACK_BACK:
				return;
				break;

			default:
				printf("Invalid Choice\n");
			break;
		}

	} while(choice!=0);

}

void queue_test()
{
	struct Queue q;
    int choice;
    int data=0;

    do
    {
        choice = queue_menu_choice();

		switch(choice)
		{
			case QUEUE_ENQUEUE:
				printf("Enter Queue Size = ");
				scanf("%d", &q.size);
				queue_create(&q, q.size);
				for(int i=1; i<=q.size; i++)
				{
					printf("Enter Data = ");
					scanf("%d", &data);
					queue_enqueue(&q, data);
				}
				queue_traverse(&q);
			break;

			case QUEUE_DEQUEUE:
				printf("Deleted : %d\n", queue_dequeue(&q));
				queue_traverse(&q);
			break;

			case QUEUE_TRAVERSE:
				queue_traverse(&q);
			break;

			case QUEUE_BACK:
				return;
				break;

			default:
				printf("Invalid Choice\n");
			break;
		}

	} while(choice!=0);
}

void circular_queue_test()
{
	struct Circular_Queue q;
    int choice;
    int data=0;

    do
    {
        choice = circular_queue_menu_choice();

		switch(choice)
		{
			case CIR_QUEUE_ENQUEUE:
				printf("Enter Queue Size = ");
				scanf("%d", &q.size);
				circular_queue_create(&q, q.size);
				for(int i=1; i<=q.size; i++)
				{
					printf("Enter Data = ");
					scanf("%d", &data);
					circular_queue_enqueue(&q, data);
				}
				circular_queue_traverse(&q);
			break;

			case CIR_QUEUE_DEQUEUE:
				printf("Deleted : %d\n", circular_queue_dequeue(&q));
				circular_queue_traverse(&q);
			break;

			case CIR_QUEUE_TRAVERSE:
				circular_queue_traverse(&q);
			break;

			case CIR_QUEUE_BACK:
				return;
				break;

			default:
				printf("Invalid Choice\n");
			break;
		}

	} while(choice!=0);

}

int array_menu_choice()
{
    int choice=0;
    printf("\n 1. Append\n 2. Insert at Index\n 3. Delete from Index\n");
    printf(" 4. Linear Search\n 5. Binary Search\n");
    printf(" 6. Max\n 7. Min\n 8. Sum\n 9. Avg\n 10. Reverse\n 11. Back\n");
    printf("Enter Choice = ");
    scanf("%d", &choice);
    return choice;
}

int linked_list_menu_choice()
{
    int choice=0;
    printf(" 1. Traverse\n 2. Insert at First\n 3. Insert at Index\n 4. Insert at Last\n");
    printf(" 5. Delete at First\n 6. Insert at Index\n 7. Delete at Last\n 8. Count Nodes\n 9. Back\n");
    printf("Enter Choice = ");
    scanf("%d", &choice);
    return choice;
}

int stack_menu_choice()
{
	int choice=0;
	printf(" 1. Push\n 2. Pop\n 3. peek\n 4. stackTop\n 5. Back\n");
    printf("Enter Choice = ");
    scanf("%d", &choice);
    return choice;
}

int queue_menu_choice()
{
	int choice=0;
	printf(" 1. Enqueue\n 2. Dequeue\n 3. Traverse\n 4. Back\n");
    printf("Enter Choice = ");
    scanf("%d", &choice);
    return choice;
}

int circular_queue_menu_choice()
{
	int choice=0;
	printf(" 1. Circular Enqueue\n 2. Circular Dequeue\n 3. Circular Traverse\n 4. Back\n");
    printf("Enter Choice = ");
    scanf("%d", &choice);
    return choice;
}
