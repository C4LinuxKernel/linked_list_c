#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

Node *insert_at_head (Node *head, int new_value);

int main () {
	Node *list1_head = NULL;
	
	list1_head = insert_at_head (list1_head, 10);	print_list (list1_head);	
}

Node *insert_at_head (Node *head, int new_value) {
	Node *new_node = calloc (1, sizeof (Node));
	
	new_node -> value = new_value;
	
	if (head == NULL) { return new_node;
	}
	
	// have some current nodes
	else {
		Node *current = head;				// set the head initially
		//				  ^
		//				  | 
		// 		  +-------+ 
		// 		  |
		//		  |							// Triverse the list until the next node is NULL
		//		¡@|
		//		¡@|					+-----> // stop
		//		¡@|					| 		    			
		while (current -> next != NULL) {	// pointer		
		//					|		^						
		//					+-----+	|	
		//						  |	|
		//						  v	|
			current = current -> next;			
		//	   ^			  	  |
		//	   |			  	  |
		//     +------------------+		
		}
		current -> next = new_node;
		
		return head;
	}
}

void print_list (Node *head) {
	Node *current;
	current = head;
	int i = 0;
	while (current != NULL) {
		printf ("Node %d: %d\n", i, current -> value);
		i++;
		current = current -> next;
	}
}
