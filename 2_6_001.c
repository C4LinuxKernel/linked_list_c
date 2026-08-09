#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node *next;
} Node;

void print_list (Node *head);
Node *insert_at_head (Node *head, int new_value);
Node *insert_at_tail (Node *head, int new_value);
Node *delete_at_head (Node *head);
Node *delete_at_tail (Node *head);
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
 // list1_head = insert_at_tail (list1_head, 10);
 // list1_head = insert_at_tail (list1_head, 12);
 // print_list (&a);
 
 	printf ("Before delete...\n");
 	print_list (list1_head);
	/*for (int i = 0; i < length; i++) {
		printf ("%d", array [i]); 
	}*/
 // list1_head = delete_at_head (list1_head);
	list1_head = delete_at_tail (list1_head);	// delete_at_tail
	
	printf ("\nAfter delete...\n");
 	print_list (list1_head);
}

int length (Node *head) {
	Node *current;
	current = head;
	int length = 0;
	while (current != NULL) {
		length++;
		current = current -> next;
	}
	return length;
}

Node *delete_at_tail (Node *head) {
	if (head == NULL) {
		return NULL;
	} else if (head -> next == NULL) {
		
		return NULL;
	} else {
		Node *current = head;				// current
		Node *prev = NULL;
		
		while (current -> next != NULL) {	// current -> next
			prev = current;
			current = current -> next;
		}
			
		prev -> next = NULL;
		free (current);
		return head;	
	}
}

Node *delete_at_head (Node *head) {
	if (head == NULL) {
		return NULL;
	} else {
		Node *to_return = head -> next;
		free (head);
		return to_return;
	}
}

Node *insert_at_tail (Node *head, int new_value) {
	Node *new_node = calloc (1, sizeof (Node));
	new_node -> value = new_value;
	if (head == NULL) {
		return new_node;
	} else {
		Node *current = head;
		while (current -> next != NULL) {
			current = current -> next;
		}
		current -> next = new_node;
		return head;
	}
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
	int i = 0;	// length
	while (current != NULL) {
		printf ("Node %d: %d\n", i, current -> value); 
		i++;	// length
		current = current -> next;
	}
}
