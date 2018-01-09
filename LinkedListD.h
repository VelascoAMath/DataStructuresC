#include "stdio.h"
#include <stdlib.h>

#ifndef LINKEDLISTD_H_
#define LINKEDLISTD_H_

int length = 0;
struct Node{
	int item;
	struct	Node* next;
	struct  Node* prev;
};

struct LinkedList
{
	struct Node * head;
	struct Node * tail;
	int length;
};

/*
Returns a pointer to a new LinkedList
*/
struct LinkedList * LinkedListInit();
/*
Returns the first item in the list
*/
int getFirst(struct LinkedList * list);

/*
Returns the last item in the list
*/
int getLast(struct LinkedList * list);

/*
Returns a pointer to an array representation of the list
*/
int * toArray(struct LinkedList * list);

/*
Returns the number of items in the list
*/
int len(struct LinkedList * list);

/*
Adds newItem to the beginning of the list
*/
void addFirst(struct LinkedList * list, int newItem);

/*
Removes the first item in the list
*/
void removeFirst(struct LinkedList * list);

/*
Removes the last item in the list
*/
void removeLast(struct LinkedList * list);

/*
Removes the item in the indexth position in the list.
*/
void removeItem(struct LinkedList * list, int index);

/*
Removes all items in the list
*/
void clear(struct LinkedList * list);

/*
Appends the newItem to the end of the list
*/
void addLast(struct LinkedList * list, int newItem);


/*
Adds the newItem in the specified index
*/
void addItem(struct LinkedList * list, int index, int newItem);


#endif