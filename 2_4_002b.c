#include <stdio.h>
#include <stdlib.h> // calloc (1, sizeof (Node));
typedef struct node {
	int value;
	struct node *next;
} Node;

void print_list (Node *head);

int main () {
	/*Node a, b, c;
	a.value = 5;
	b.value = 6;
	c.value = 7;
	a.next = &b;
	b.next = &c;
	c.next = NULL;*/
 // Node *a = NULL;
	Node *list1_head = NULL;
 // printf ("Node a.value: %d\n", a.value);
	print_list (&a);
	/*for (int i = 0; i < length; i++) {
		printf ("%d", array [i]); 
	}*/
}

Node *insert_at_head (Node *head, int new_value) {
	Node *new_node = calloc (1, sizeof (Node));	// #include <stdlib.h> 
	new_node -> value = new_value;
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
