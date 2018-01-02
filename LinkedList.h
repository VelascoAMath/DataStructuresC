#include "stdio.h"
#include <stdlib.h>

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

int length = 0;
struct Node{
	int item;
	struct	Node* next;
};
struct Node * head;

/*
Returns the first item in the list
*/
int getFirst();

/*
Returns a pointer to an array representation of the list
*/
int * toArray();

/*
Returns the number of items in the list
*/
int len();

/*
Adds newItem to the beginning of the list
*/
void addFirst(int newItem);

/*
Removes the first item in the list
*/
void removeFirst();

/*
Removes the last item in the list
*/
void removeLast();

/*
Removes the item in the indexth position in the list.
*/
void removeItem(int index);

/*
Removes all items in the list
*/
void clear();

/*
Appends the newItem to the end of the list
*/
void addLast(int newItem);


/*
Adds the newItem in the specified index
*/
void addItem(int index, int newItem);


#endif