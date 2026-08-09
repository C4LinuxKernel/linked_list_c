#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node; 

Node *delete_at_tail (Node *head);

int main () {
	
	Node *list1_head = NULL;
	
	list_head = insert_at_head (list_head, 7);
	list_head = insert_at_head (list_head, 5);
	list_head = insert_at_head (list_head, 3);
	list_head = insert_at_head (list_head, 7);
	list_head = insert_at_head (list_head, 7);
	
}

Node *delete_at_tail (Node *head) {
//
//				 +------------------> 	NULL 
//				 |
	if (head == NULL) {	return NULL;	// it is emtpy just return emtpy
	
	// if there is only one node
	// the head node is going to point to head node because it is also the tail
	// if that is the case, just free head because that is the only node
	} else if (head -> next == NULL) {	
	
		free (head);	// because that is the only node
	
		return NULL;
	
	} else {
	
		Node *current;
//				^
//				+---------------------------+
		Node *prev;	//						|
//				^							|
//				+-------------+				|
		current = head;	// 	  |			 pointer
//							  | 
		prev = NULL;	// pointer
		
		while (current -> next != NULL) {
	
			prev = current;
	
			current = current -> next;
		}
		prev -> next = NULL;
	
		free (current);
	
		return head;
	}
}
