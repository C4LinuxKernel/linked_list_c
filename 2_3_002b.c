#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

int main () {
	Node a, b, c;
	a.value = 5;
	b.value = 6;
	c.value = 7;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	// printf ("Node a.value: %d\n", a.value);
}
