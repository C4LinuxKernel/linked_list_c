#include <stdio.h>

typedef struct node {
	int value;	// eg: array, string, struct
	struct node *next;
} Node;

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
	
	// Question: how to print out all the nodes in a linked list?
/*	for (int i = 0; i < length; i++) {	// no loop through the linked list
		printf ("%d", array [i]);	// no index as with arrays
	}	*/

	// Data structure: when we access the data inside them, called traversing.
	
	
	// Traversing: using pointer, creating a pointer that initially point to head node.
	// point to node a: had that pointer continually set to be next node in list 
	// Traversing linked list: continually set to be next node in list until it is NULL
	
}
