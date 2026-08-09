#include <stdio.h>
#include <stdlib.h>	// calloc (1, sizeof (Node));
typedef struct node {
	int value;
	struct node *next;
} Node;

void print_list (Node *head);
Node *insert_at_head (Node *head, int new_value);	// insert_at_head
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
	list1_head = insert_at_head (list1_head, 7);
	list1_head = insert_at_head (list1_head, 5);
	list1_head = insert_at_head (list1_head, 3);
 // print_list (&a);
 	print_list (list1_head);
	/*for (int i = 0; i < length; i++) {
		printf ("%d", array [i]); 
	}*/
}

Node *insert_at_head (Node *head, int new_value) {
	Node *new_node = calloc (1, sizeof (Node));
	new_node -> value = new_value;
	
	if (head == NULL) {
		return new_node;
	} else {
		new_node -> next = head;
		return new_node;
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
