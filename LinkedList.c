#include "stdio.h"
#include <stdlib.h>
#include "LinkedList.h"


/*
 Returns the first item
*/
 int getFirst(){
 	return head->item;
 }

 int * toArray(){
 	int * result = (int*) malloc(sizeof(int) * length);
 	if(length == 0)
 		return result;
 	result[0] = head->item;
 	struct	Node * temp = head;
 	for(int i = 1; i < length; i++){
 		temp = temp -> next;
 		result[i] = temp -> item;
 	}
 	return result;
 }

 int len(){
 	return length;
 }
 void addFirst(int newItem){
 	if(length == 0){
 		head = (struct Node*) malloc(sizeof(struct Node));
 		head->item = newItem;
 		head->next = NULL;
 	} else {
 		struct	Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode -> item = newItem;
 		newNode -> next = head;
 		head = newNode;
 	}
 	length++;
 }


 void removeFirst(){
 	if(length > 0){
 		if(length == 1){
 			free(head);
 			length = 0;
 		} else {
 			struct	Node * temp = head;
 			head = head -> next;
 			temp -> next = NULL;
 			free(temp);
 			length--;
 		}
 	}

 }

 void removeLast(){
 	if(length == 1){
 		free(head);
 	} else{
 		struct Node* temp = head;
 		while(temp -> next -> next != NULL){
 			temp = temp -> next;
 		}
 		struct Node * prevTemp = temp;
 		temp = temp -> next;
 		free(temp);
 		prevTemp -> next = NULL;
 	}
 	length--;
 }


 void removeItem(int index){
 	if(index == 0){
 		removeFirst();
 	} else if(index == length - 1){
 		removeLast();
 	} else {
 		struct	Node * temp = head;
 		for(int i = 1; i < index; i++){
 			temp = temp -> next;
 		}
 		struct	Node * removedTemp = temp -> next;
 		temp -> next = removedTemp -> next;
 		free(removedTemp);
 		length--;
 	}
 }

 void clear(){
 	while(length > 0){
 		removeFirst();
 	}
 }
 void addLast(int newItem){
 	if(length == 0){
 		head = (struct Node*) malloc(sizeof(struct Node));
 		head->item = newItem;
 		head->next = NULL;
 	} else{
 		struct Node* temp = head;
 		while(temp -> next != NULL){
 			temp = temp -> next;
 		}
 		struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
 		temp->next = newNode;
 		newNode -> item = newItem;
 		newNode -> next = NULL;
 	}
 	length++;
 }


 void addItem(int index, int newItem){
 	if(index == 0){
 		addFirst(newItem);
 	} else if(index == length){
 		addLast(newItem);
 	} else if (index <= length){
 		struct	Node * temp = head;
 		for(int i = 1; i <= index; i++){
 			temp = temp -> next;
 		}
 		struct	Node * newNode = (struct Node *) malloc(sizeof(struct Node));
 		newNode -> item = newItem;
 		newNode -> next = temp -> next;
 		temp -> next = newNode;
 		length++;

 	}
 }

 int main(int argc, char ** argv){
 	if(argc > 1){
 		for(int i = 1; i < argc; i++){
 			int item = atoi(argv[i]);
 			addLast(item);
 		}
 	}
 	else{
 		for(int i = 2; i < 100000; i++){
 			addFirst(i);
 		}
 	}
 	int * a = toArray();
 	for(int i = 0; i < len(); i++){
 		printf("%d ", a[i]);
 	}
 	printf("\n");
 	return 0;
 }