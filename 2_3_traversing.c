#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

int main () {
	
	// Traversing the list
	Node a;	//<-------------+	// head of list
	//					 	|
	//					 	|
	//					 	|
	Node b;	// 			 	|
			// 			 	|
	Node c;	// 			 	| 
			//			 	|										
	a.value = 5;	// 	current: is initially going to be head of list "a"					
	//	|	  ^							
	//	|	  |							
	//	|	  +------Node 0: 5	 		
	//	|								
	//  +-------------------------------|
	//									|
	// current = current -> next		|
	b.value = 6;	// <----------------+
	//	|	  ^			 
	//	|	  |
	//  |	  +------Node 1: 6	 
	//	+-------------------------------+
	//									|
	//									|
	// current = current -> next		|
	c.value = 7;	//<-----------------+
	//	|	  ^			 
	//	|	  |
	//  |	  +------Node 2: 7	 
	//	+-------------------------------+
	//									|
	// creat linked list on stack		|
	a.next = &b;	//					|
	// |								|
	// |								|
	// v								|
	b.next = &c;	// 					|
	// |								|
	// |								|
	// v								|
	c.next = NULL;	// tail	<-----------+
}
