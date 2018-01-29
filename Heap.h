#include "stdio.h"
#include <stdlib.h>

// Author: Alfredo Velasco
// This is an implementation of a binary heap
struct Heap {
	int* heap;
	int length;
	int totalSize;
};

struct Heap * newHeap();

/*
This prints out the contents of the heap.
*/
void printHeap(struct Heap *);

/*
This swaps elements in the given indices
*/
void swap(struct Heap *, int a, int b);

/*
Simple sifting up function.
Sifts up the item from the given index
*/
void siftUp(struct Heap *, int index);

/*
Simple sifting down function.
Sifts down the item from the given index
*/
void siftDown(struct Heap *, int index);

/*
Adds the item to the heap
*/
void add(struct Heap *, int newVal);

/*
Returns the item at the top of the heap
*/
int peek(struct Heap *);

/*
Returns the item at the top of the heap and removes it.
*/
int poll(struct Heap *);