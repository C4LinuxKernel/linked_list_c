Node *efficient_delete_match (Node *head, int delete_value, int *num_delete) {
	*num_deleted = 0;
	
	if (head == NULL) {	return NULL;
	}
	Node *current, *temp;
	current = head;
	
	while (current -> value == delete_value) {
	
		temp = current;
		current = current -> next;
		free (temp);
		*num_deleted = *num_deleted + 1;
		
		if (current == NULL) {	return NULL;
		}
	}
	new_head = current;
	
	while (current -> next != NULL) {
		
		if (current -> next -> value == delete_value) {
		
			temp = current -> next;
			current -> next = current -> next -> next;
			free (temp);
			*num_deleted = *num_deleted + 1;
		}
	}
}
