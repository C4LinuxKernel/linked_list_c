Node *delete_first_match (Node *head, int delete_value, bool *was_delete) {
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
	Node *prev - head;
	
	while (current != NULL) {
		if (current -> value == delete_value) {
			prev -> next = current -> next;
			free (current);
			*was_deleted = true;
			return head;
		}
		prev = current;
		current = current -> next;
	}
	*was_deleted = false;
	return head;
}


