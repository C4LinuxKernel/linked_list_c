Node *delete_all_matches (Node *head, int delete_value, int *num_deleted) {
	Node *current  = head;
	bool deleted = false;
	*num_deleted = 0;
	
	do {
		current = delete_first_match (current, delete_value, &deleted);
		if (deleted) {	*num_deleted = *num_deleted + 1;
		} while (deleted);
	}
	return current;
}
