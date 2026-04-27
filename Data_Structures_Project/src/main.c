/*
 ============================================================================
 Name        : main.c
 Author      : Sunil Sutar
 Version     :
 Copyright   : Your copyright notice
 Description : Implementation of Array, Linked List, Stack, Queue and Circular Queue.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"

int menu_choice();

struct Node *head = NULL;

int main()
{
    int choice;

    do
    {
        choice = menu_choice();

        switch (choice)
        {
        	case 1:
        		array_test();
        	break;

            case 2:
            	linked_list_test(head);
            break;

            case 3:
            	stack_test();
            break;

            case 4:
            	queue_test();
            break;

            case 5:
            	circular_queue_test();
            break;

            default:
                printf("Invalid Choice\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

int menu_choice()
{
    int choice=0;
    printf(" 1. Array Menu\n 2. Linked List Menu\n 3. Stack Menu\n");
    printf(" 4. Queue Menu\n 5. Circular Queue Menu\n");
    printf("Enter Choice = ");
    scanf("%d", &choice);
    return choice;
}
