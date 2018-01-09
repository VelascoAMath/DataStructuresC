#include "stdio.h"
#include <stdlib.h>
#include "LinkedListD.h"


struct LinkedList * LinkedListInit(){
	struct LinkedList * list = malloc(sizeof(struct LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

/*
 Returns the first item
*/
 int getFirst(struct LinkedList * list){
 	return list->head->item;
 }

 int getLast(struct LinkedList * list){
 	return list->tail->item;
 }

 int * toArray(struct LinkedList * list){
 	int * result = (int*) malloc(sizeof(int) * list->length);
 	if(list->length == 0)
 		return result;
 	result[0] = list->head->item;
 	struct	Node * temp = list->head;
 	for(int i = 1; i < list->length; i++){
 		temp = temp -> next;
 		result[i] = temp -> item;
 	}
 	return result;
 }

 int * toArrayBW(struct LinkedList * list){
 	int * result = (int*) malloc(sizeof(int) * list->length);
 	if(list->length == 0)
 		return result;
 	struct	Node * temp = list->tail;
 	for(int i = 0; i < list->length; i++){
 		result[i] = temp -> item;
 		temp = temp->prev;
 	}
 	return result;
 }

 int len(struct LinkedList * list){
 	return list->length;
 }
 void addFirst(struct LinkedList * list, int newItem){
 	if(list->length == 0){
 		list->head = (struct Node*) malloc(sizeof(struct Node));
 		list->head->item = newItem;
 		list->head->next = NULL;
 		list->head->prev = NULL;

 		list->tail = list->head;
 	} else {
 		struct	Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode -> item = newItem;
 		newNode -> next = list->head;
 		newNode -> prev = NULL;
 		list->head->prev = newNode;
 		list->head = newNode;
 	}
 	list->length++;
 }


 void removeFirst(struct LinkedList * list){
 	if(list->length > 0){
 		if(list->length == 1){
 			free(list->head);
 			list->length = 0;
 		} else {
 			struct	Node * temp = list->head;
 			list->head = (list->head)-> next;
 			free(temp);
 			list->length--;
 		}
 	}

 }

 void removeLast(struct LinkedList * list){
 	if(list->length == 1){
 		free(list->head);
 		list->head = NULL;
 		list->tail = NULL;
 	} else{
 		list->tail = list->tail->prev;
 		free(list->tail->next);
 		list->tail->next = NULL;
 	}
 	list->length--;
 }

void removeItem(struct LinkedList * list, int index){
 	if(index == 0){
 		removeFirst(list);
 	} else if(index == list->length - 1){
 		removeLast(list);
 	} else if (index < list->length / 2){
 		struct	Node * temp = list->head;
 		for(int i = 0; i < index; i++){
 			temp = temp -> next;
 		}
 		temp->prev->next = temp->next;
 		temp->next->prev = temp->prev;
 		free(temp);
 		list->length--;

 	} else {
 		struct Node * temp = list->tail;
 		for(int i = list->length - 1; i > index; i--){
 			temp = temp -> prev;
 		}
 		temp->prev->next = temp->next;
 		temp->next->prev = temp->prev;
 		free(temp);
 		list->length--;

 	}
 }

 void clear(struct LinkedList * list){
 	while(list->length > 0){
 		removeLast(list);
 	}
 }
 void addLast(struct LinkedList * list, int newItem){
 	if(list->length == 0){
 		list->head = (struct Node*) malloc(sizeof(struct Node));
 		list->head->item = newItem;
 		list->head->next = NULL;
 		list->head->prev = NULL;
 		list->tail = list->head;
 		list->tail->next = NULL;
 		list->tail->prev = NULL;
 	} else{
 		struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
 		list->tail->next = newNode;
 		newNode->prev = list->tail;
 		newNode->item = newItem;
 		list->tail = list->tail->next;
 	}
 	list->length++;
 }


 void addItem(struct LinkedList * list, int index, int newItem){
 	if(index == 0){
 		addFirst(list, newItem);
 	} else if(index == list->length){
 		addLast(list, newItem);
 	} else if (index < list->length / 2){
 		struct	Node * temp = list->head;
 		for(int i = 1; i < index; i++){
 			temp = temp -> next;
 		}
 		struct	Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode -> item = newItem;
 		newNode -> next = temp -> next;
 		temp ->next->prev = newNode;
 		newNode -> prev = temp;
 		temp -> next = newNode;
 		list->length++;

 	} else {
 		struct Node * temp = list->tail;
 		for(int i = list->length; i > index; i--){
 			temp = temp -> prev;
 		}
 		struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode->item = newItem;
 		newNode->next = temp->next;
 		newNode->prev = temp;
 		temp->next->prev = newNode;
 		temp->next = newNode;
 		list->length++;

 	}
 }

 int main(int argc, char ** argv){
 	struct LinkedList * list = LinkedListInit();
 	if(argc > 1){
 		for(int i = 1; i < argc; i++){
 			int item = atoi(argv[i]);
 			addLast(list, item);
 		}
 	}
 	else{
 		addFirst(list, 0);
 		addItem(list, 1, 1);
 		addItem(list, 1, 1);
 		for(int i = 0; i < 10; i++){
 			addItem(list, 1, i);
 		}
 		for(int i = 0; i < 10; i++){
 			removeItem(list, list->length - 2);
 		}
 	}
 	int * a = toArray(list);
 	for(int i = 0; i < len(list); i++){
 		printf("%d ", a[i]);
 	}
 	printf("\n");
 	free(a);
 	a = toArrayBW(list);
 	for(int i = 0; i < len(list); i++){
 		printf("%d ", a[i]);
 	}
 	printf("\n");
 	clear(list);
 	free(list);
 	free(a);
 	return 0;
 }