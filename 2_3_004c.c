#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

void print_list (Node *head);

int main () {
	Node a, b, c;
	a.value = 5;
	b.value = 6;
	c.value = 7;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	// printf ("Node a.value: %d\n", a.value);
	
	/*for (int i = 0; i < length; i++) {
		printf ("%d", array [i]); 
	}*/
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
