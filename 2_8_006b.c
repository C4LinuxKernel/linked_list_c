#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>		// %fs\n: (double) (toc - tic) / CLOCKS_PER_SEC
typedef struct node {
	int value;
	struct node *next;
} Node;

void print_list (Node *head);
Node *insert_at_head (Node *head, int new_value);
Node *insert_at_tail (Node *head, int new_value);
Node *delete_at_head (Node *head);
Node *delete_at_tail (Node *head);
int length (Node *head);
int recursive_length (Node *node);
bool is_member (Node *node, int find_value);
int count_matches (Node *node, int find_value);
void replace_match (Node *node, int find_value, 
					int replace_value);	
Node *delete_first_match (Node *head, int delete_value, 
						  bool *was_deleted);	
Node *delete_all_match (Node *head, int delete_value, 
						int *num_deleted);
Node *efficient_delete_match (Node *head, int delete_value, 
							  int *num_deleted);	
int main () {
	/*Node a, b, c;
	a.value = 5;
	b.value = 6;
	c.value = 7;
	a.next = &b;
	b.next = &c;
	c.next = NULL;*/
 // Node *a = NULL;
 	Node *list8 = NULL;
 //	Node *list1_head = NULL;
 // printf ("Node a.value: %d\n", a.value);
 	list8 = insert_at_head (list8, 4);
 	list8 = insert_at_head (list8, 3);
 	list8 = insert_at_head (list8, 4);
 	list8 = insert_at_head (list8, 4);
 	list8 = insert_at_head (list8, 5);
 	list8 = insert_at_head (list8, 4);
 	list8 = insert_at_head (list8, 4);
 	list8 = insert_at_head (list8, 7);
 	list8 = insert_at_head (list8, 4);
 	list8 = insert_at_head (list8, 4);
 //	list1_head = insert_at_head (list1_head, 7);
 //	list1_head = insert_at_head (list1_head, 5);
 //	list1_head = insert_at_head (list1_head, 3);
 //	list1_head = insert_at_head (list1_head, 5);
 //	list1_head = insert_at_head (list1_head, 5);
 //	list1_head = insert_at_head (list1_head, 3);
 // list1_head = insert_at_tail (list1_head, 10);
 // list1_head = insert_at_tail (list1_head, 12);
 // print_list (&a);
 
 //	printf ("Before delete...\n");
 //	print_list (list1_head);
	/*for (int i = 0; i < length; i++) {
		printf ("%d", array [i]); 
	}*/
 // list1_head = delete_at_head (list1_head);
 //	list1_head = delete_at_tail (list1_head);	
	
 //	printf ("\nAfter delete...\n");
 //	print_list (list1_head);
 // printf ("Linked List Length: %d\n", length (list1_head));
 // printf ("Linked List Length: %d\n", recursive_length (list1_head));
	/*if (is_member (list1_head, 5)) {
		printf ("5 is in the list!\n");
	} else {
		printf ("5 is not in the list!\n");
	}
	
	if (is_member (list1_head, 8)) {
		printf ("8 is in the list!\n");
	} else {
		printf ("8 is not in the list!\n");
	}*/
	
 //	printf ("Number of 3s: %d\n", count_matches (list1_head, 3));
 //	printf ("Number of 5s: %d\n", count_matches (list1_head, 5));
 //	printf ("Number of 7s: %d\n", count_matches (list1_head, 7));
 //	printf ("Number of 8s: %d\n", count_matches (list1_head, 8));
	
 //	printf ("List before replacement:\n");
 //	print_list (list1_head);
 	/*replace_matches (list1_head, 5, 9);
 	replace_matches (list1_head, 7, 8);
 	replace_matches (list1_head, 8, 128);*/
 //	printf ("List after replacement:\n");
 //	print_list (list1_head);
 
 //	printf ("List before any deletions... \n");
 //	print_list (list1_head);
	
 //	bool deleted;
 	/*int num_deleted;
	list1_head = 
		delete_all_match (list1_head, 3, &num_deleted);*/
	 // delete_first_match (list1_head, 3, &deleted);
	/*if (deleted) {
		printf ("A node with value 3 was deleted!\n");
	} else {
		printf ("A node with value 3 was not deleted!\n"); 
	}*/
 //	printf ("%d 3s deleted\n", num_deleted);
 //	printf ("List after deleting all 3s...\n");
 //	printf ("List after deleting 3...\n");
 //	print_list (list1_head);
	
	
 	/*list1_head =
		delete_all_match (list1_head, 5, &num_deleted);*/
  /*list1_head =
		delete_first_match (list1_head, 3, &deleted);
	if (deleted) {
		printf ("A node with value 8 was deleted!\n");
	} else {
		printf ("A node with value 8 was not deleted!\n"); 
	}*/
 //	printf ("%d 5s deleted\n", num_deleted);
 //	printf ("List after deleting all 5s...\n");
 //	printf ("List after deleting 8...\n");
 //	print_list (list1_head);
	
	printf ("List...\n");
	print_list (list8);
	int num_deleted = 0;
	list8 = efficient_delete_match (list8, 4, &num_deleted);	
	printf ("\nList after delete...\n");
	print_list (list8);
	printf ("Number of elements deleted: %d\n", num_deleted);
																
	Node *list9  = NULL;
	Node *list10 = NULL;
	int i;
	for (i = 0;i < 50000; i++) {
		list9 = insert_at_head (list9, i % 10);
	}
	for (i = 0;i < 50000; i++) {
		list10 = insert_at_head (list10, i % 10);
	}
	
	clock_t tic, toc;
	
	tic = clock ();
	list9 = delete_all_match (list9, 4, &num_deleted);
	toc = clock ();
	printf ("delete_all_matches: %fs\n", 
			(double) (toc - tic) / CLOCKS_PER_SEC);	// #include <time.h>	
	printf ("elements deleted: %d\n", num_deleted);
	
	tic = clock ();
	list10 = delete_all_match (list10, 4, &num_deleted);
	toc = clock ();
	printf ("efficient_delete_matches: %fs\n", 
			(double) (toc - tic) / CLOCKS_PER_SEC);	// #include <time.h>	
	printf ("elements deleted: %d\n", num_deleted);
	 
}

Node *efficient_delete_match (Node *head, int delete_value, 
							  int *num_deleted) {	
	*num_deleted = 0;
	if (head == NULL) {
		return NULL;
	}
	
	Node *current, *temp, *new_head;			
	current = head;
	while (current -> value == delete_value) {		
		temp = current;
		current = current -> next;						
		free (temp);								
		*num_deleted = *num_deleted + 1;
		
		if (current == NULL) {
			return NULL;
		}
	}
	new_head = current;	

	while (current -> next != NULL) {				
		if (current -> next -> value == delete_value) {
			temp = current -> next;
			current -> next = current -> next -> next;
			free (temp);								
			*num_deleted = *num_deleted + 1; 
		} else {
			current = current -> next;
		}
	}				
}

Node *delete_all_match (Node *head, int delete_value, 
						int *num_deleted) {				
	Node *current = head;
	bool deleted = false;
	*num_deleted = 0;
	
	do {													
		current = delete_first_match (current, delete_value,
									  &deleted);
		if (deleted) {
			*num_deleted = *num_deleted + 1;
		} 
	} while (deleted);
	return current;
}

Node *delete_first_match (Node *head, int delete_value, 
						  bool *was_deleted) {			
	if (head == NULL) {
		*was_deleted = false;
		return NULL;				  		
	}
	if (head -> value == delete_value) {
		Node *temp = head -> next;
		free (head);
		*was_deleted = true;
		return temp;
	}
	Node *current = head -> next;						
	Node *prev = head;									
	
	while (current != NULL) {							
		if (current -> value == delete_value) {			
			prev -> next = current -> next;				
			free (current);							
			*was_deleted = true;	
			return head;
		}
		prev  = current;
		current = current -> next;					
	}
	*was_deleted = false;		
	return head;
}

void replace_matches (Node *node, int find_value, 
					int replace_value) {
	if (node != NULL) {
		if (node -> value == find_value) {
			node -> value = replace_value;
		}
		replace_matches (node -> next, find_value, 
						 replace_value);
	}
}

int count_matches (Node *node, int find_value) {
	if (node == NULL) {
		return 0;
	} else if (node -> value == find_value) {
		return 1 + count_matches (node -> next, find_value);
	} else {
		return count_matches (node -> next, find_value);
	}
}
 
bool is_member (Node *node, int find_value) {
	if (node == NULL) {
		return false;
	} else if (node -> value == find_value) {
		return true;
	} else {
		return is_member (node -> next, find_value);
	}
} 

int recursive_length (Node *node) {
	if (node == NULL) {
		return 0;
	} else {
		return 1 + recursive_length (node -> next);
	}
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
		Node *current = head;			
		Node *prev = NULL;
		
		while (current -> next != NULL) {
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
