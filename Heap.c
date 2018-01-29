#include "Heap.h"

// Author: Alfredo Velasco

struct Heap * newHeap(){
	struct Heap * newHeap = (struct Heap *) malloc(sizeof(struct Heap));
	newHeap->length = 0;
	newHeap->totalSize = 0;
	return newHeap;
}

void swap(struct Heap * heap, int a, int b){
	// printf("Swapping %d %d and %d %d\n", a, heap[a], b, heap[b]);
	int temp = heap->heap[a];
	heap->heap[a] = heap->heap[b];
	heap->heap[b] = temp;
}

void siftUp(struct Heap * heap, int index){
	while(index > 0 && heap->heap[(index - 1) / 2] > heap->heap[index]) {
		swap(heap, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

void siftDown(struct Heap * heap, int index){
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	// printf("Sift %d %d %d %d\n", index, left, right, heap->length);
	// 0 
	if(left >= heap->length){
		return;
	} 
	// 0 1
	else if(right >= heap->length && heap->heap[index] > heap->heap[left]){
		swap(heap, index, left);
		siftDown(heap, left);
	}
	// 0 1 2
	else if(right < heap->length && (heap->heap[index] > heap->heap[left] || heap->heap[index] > heap->heap[right])){
		if(heap->heap[left] < heap->heap[right]){
			swap(heap, index, left);
			siftDown(heap, left);
		} else{
			swap(heap, index, right);
			siftDown(heap, right);
		}
	}
	return;
}

void add(struct Heap * heap, int newVal){
	if(heap->length == heap->totalSize){
		heap->totalSize = heap->totalSize * 2 + 1;
		heap->heap = (int *) realloc(heap->heap, sizeof(int) * (heap->totalSize));
	}
	heap->heap[heap->length] = newVal;
	siftUp(heap, heap->length);
	heap->length++;
}

int peek(struct Heap * heap){
	return heap->heap[0];
}

int poll(struct Heap * heap){
	// printHeap();
	int result = heap->heap[0];
	if(--(heap->length) == heap->totalSize / 2){
		swap(heap, 0, heap->length);
		heap->totalSize = heap->totalSize / 2;
		heap->heap = (int *) realloc(heap->heap, sizeof(int) * (heap->totalSize));
		// printHeap();
	} else {
		swap(heap, 0, heap->length);
	}
	siftDown(heap, 0);
	// printHeap();
	return result;
}

void printHeap(struct Heap * heap){
	printf("Heap = ");
	for(int i = 0; i < heap->length; i++){
		printf("%d ", heap->heap[i]);
	}
	printf("\n");
}

int main(){
	struct Heap * heap = newHeap();
	for(int i = 2000000000 - 1; i > -1; i--){
		add(heap, i);
		if(i % 10000 == 0){
		  printf("%d ", i);
		}
		// printf("%d %d\n", heap->length, totalSize);
	}
	// for(int i = 0; i < heap->length; i++){
	// 	printf("%d ", poll());
	// }
	while(heap->length > 0)
	{
	  poll(heap);
	  // printf("%d is min\n", poll());
	}
	free(heap);
	return 0;
}
