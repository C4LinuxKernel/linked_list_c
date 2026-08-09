#include <stdio.h>
#include <stdlib.h>	// calloc

typedef struct node {
	int value;
	struct node *next;
} Node; 

int main () {
	Node *list1_head = NULL;	// Node *a = NULL;
	
	list1_head = insert_at_head (list1_head, 7);
}

Node *insert_at_head (Node *head, int new_value) {
	
	Node *new_node = calloc (1, sizeof (Node));
	// 		^			^			^
	//		|			|			+----------new_node on the heap
	//		|			+----------------------Dynamic allocate memory for "1"
	//		+-----------------------------+
	//									  |
	//									  |	
	//									  |
	new_node -> value = new_value;	// pointer
	//  ^					^
	//	|					|
	//	|					+------------------new_value are going to insert to list
	//	|					
	//	+--------------------------+				
	//							   |					
	//							   | 
	if (head == NULL) {	return new_node; 	// the head and the tail are same thing
	}
	
	// Question: what do we have to get to the end of list to insert it?
	else {
		new_node -> next = head;
		return new_node;
	}
}
