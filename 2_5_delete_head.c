#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

Node *insert_at_head (Node *head, int new_value);
Node *delete_at_head (Node *head);

int main () {
	Node *list1_head = NULL;
	
	list1_head = insert_at_head (list1_head, 7);	print_list (list1_head);
	
	list1_head = delete_at_head (list1_head);		print_list (list1_head);
	
}

Node *delete_at_head (Node *head) {
	if (head == NULL) {	return NULL;
	} else {
		Node *to_return = head -> next;
		free (head);
		return to_return;
	}
} 

Node *insert_at_head (Node *head, int new_value) {
	
	Node *new_node = calloc (1, sizeof (Node));
	
	new_node -> value = new_value;
	
	if (head == NULL) { return new_node;	// wrong: return NULL;
	} else {	// Question: what do we have to get to the end of list to insert it?
		Node *current = head;	// wrong: current -> next;
		
		// Triverse the list until the next node is NULL
		while (current -> next != NULL) {	current = current -> next;
		}
		current -> next = new_node;	// wrong: new_value;
		return head;	// wrong: return new_value;
	}
}

void print_list () {
	
}

