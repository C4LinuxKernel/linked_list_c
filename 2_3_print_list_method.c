#include <stdio.h>

typedef struct node {
	int value;
	struct node *next; 
} Node;

void print_list (Node *head);

int main () {
	Node a;
	Node b;
	Node c;
	a.value = 5; printf ("Node a.value: %d\n", a.value);
	b.value = 6;
	c.value = 7;
	// creat linked list on stack
	a.next = &b;	
	// |
	// |
	// |				
	// v				
	b.next = &c;	
	// |
	// |
	// |				
	// v
	c.next = NULL;	// tail
}

// make a print list method
void print_list (Node *head) {
	
	Node *current;	//<--+
	//                 	 |
	//				   	 | 
	// +-----------------+
	// |
	current = head;	// current: a pointer to a node
	int i = 0;
	
	// until the current is equal the NULL, and loop is done
	while (current != NULL) {	// so long is not NULL
	
		printf ("Node %d: %d\n", i, current -> value);
		i++;
		
		// a pointer to the next node in list
		current = current -> next;	// set current to be this node "next" value
		// |				^	
		// |				|
		// +----------------+
	}
}
