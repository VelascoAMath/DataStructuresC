#include "stdio.h"
#include <stdlib.h>
#include "LinkedList.h"


struct LinkedList * LinkedListInit(){
	struct LinkedList * list = malloc(sizeof(struct LinkedList));
	list->head = NULL;
	list->length = 0;
	return list;
}

/*
 Returns the first item
*/
 int getFirst(struct LinkedList * list){
 	return list->head->item;
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

 int len(struct LinkedList * list){
 	return list->length;
 }
 void addFirst(struct LinkedList * list, int newItem){
 	if(list->length == 0){
 		list->head = (struct Node*) malloc(sizeof(struct Node));
 		list->head->item = newItem;
 		list->head->next = NULL;
 	} else {
 		struct	Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode -> item = newItem;
 		newNode -> next = list->head;
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
 	} else{
 		struct Node* temp = list->head;
 		while(temp -> next -> next != NULL){
 			temp = temp -> next;
 		}
 		struct Node * prevTemp = temp;
 		temp = temp -> next;
 		free(temp);
 		prevTemp -> next = NULL;
 	}
 	list->length--;
 }


 void removeItem(struct LinkedList * list, int index){
 	if(index == 0){
 		removeFirst(list);
 	} else if(index == list->length - 1){
 		removeLast(list);
 	} else {
 		struct	Node * temp = list->head;
 		for(int i = 1; i < index; i++){
 			temp = temp -> next;
 		}
 		struct	Node * removedTemp = temp -> next;
 		temp -> next = removedTemp -> next;
 		free(removedTemp);
 		list->length--;
 	}
 }

 void clear(struct LinkedList * list){
 	while(list->length > 0){
 		removeFirst(list);
 	}
 }
 void addLast(struct LinkedList * list, int newItem){
 	if(list->length == 0){
 		list->head = (struct Node*) malloc(sizeof(struct Node));
 		list->head->item = newItem;
 		list->head->next = NULL;
 	} else{
 		struct Node* temp = list->head;
 		while(temp -> next != NULL){
 			temp = temp -> next;
 		}
 		struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
 		temp->next = newNode;
 		newNode -> item = newItem;
 		newNode -> next = NULL;
 	}
 	list->length++;
 }


 void addItem(struct LinkedList * list, int index, int newItem){
 	if(index == 0){
 		addFirst(list, newItem);
 	} else if(index == list->length){
 		addLast(list, newItem);
 	} else if (index < list->length){
 		struct	Node * temp = list->head;
 		for(int i = 1; i < index; i++){
 			temp = temp -> next;
 		}
 		struct	Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode -> item = newItem;
 		newNode -> next = temp -> next;
 		temp -> next = newNode;
 		list->length++;

 	}
 }

 int main(int argc, char ** argv){
 	struct LinkedList * list = LinkedListInit();
 	if(argc > 1){
 		for(int i = argc - 1; i > 0; i--){
 			int item = atoi(argv[i]);
 			addFirst(list, item);
 		}
 	}
 	else{
 		for(int i = 0; i < 1000; i++){
 			addFirst(list, i);
 		}
 	}
 	int * a = toArray(list);
 	for(int i = 0; i < len(list); i++){
 		printf("%d ", a[i]);
 	}
 	printf("\n");
 	clear(list);
 	free(list);
 	free(a);
 	return 0;
 }