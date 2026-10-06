#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *insert_at_head (Node *head, int value);
Node *insert_at_tail (Node *head, int value);

Node *delete_first_match (Node *head, int value);
Node *delete_all_matches (Node *head, int value, int *num_deleted);

Node *reverse_list (Node *head);

size_t list_length (Node *head);
bool is_list_contains (Node *head, int value);

void free_list (Node *head);

#endif // LINKED_LIST_H