#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "linked_list.h"

/* =========================================================
 * Test helpers
 * ========================================================= */

 static void assert_list (Node *head, const int *expexted, size_t n) {
    Node *current = head;

    for (size_t i = 0; i < n; i++) {
        assert (current != NULL);
        assert (current -> value == expected [i]);

        current = current -> next;
    }
    assert (current == NULL);
 }

 static Node *make_list (const int *values, size_t n) {
    
    Node *head = NULL;

    for (size_t i = 0; i < n; i++) {
        head = insert_at_tail (head, values [i]);
    }

    return head;
 })

 
/* =========================================================
 * insert_at_head
 * ========================================================= */


static void test_insert_at_head_empty(void)
{
    Node *head = NULL;

    head = insert_at_head(head, 10);

    int expected[] = {10};

    assert_list(head, expected, 1);

    free_list(head);

    printf("PASS: insert_at_head_empty\n");
}

static void test_insert_at_head(void)
{
    Node *head = NULL;

    head = insert_at_head(head, 10);
    head = insert_at_head(head, 20);
    head = insert_at_head(head, 30);

    int expected[] = {30, 20, 10};

    assert_list(head, expected, 3);

    free_list(head);

    printf("PASS: insert_at_head\n");
}

/* =========================================================
 * insert_at_tail
 * ========================================================= */

static void test_insert_at_tail_empty(void)
{
    Node *head = NULL;

    head = insert_at_tail(head, 10);

    int expected[] = {10};

    assert_list(head, expected, 1);

    free_list(head);

    printf("PASS: insert_at_tail_empty\n");
}

static void test_insert_at_tail(void)
{
    Node *head = NULL;

    head = insert_at_tail(head, 10);
    head = insert_at_tail(head, 20);
    head = insert_at_tail(head, 30);

    int expected[] = {10, 20, 30};

    assert_list(head, expected, 3);

    free_list(head);

    printf("PASS: insert_at_tail\n");
}

/* =========================================================
 * delete_at_head
 * ========================================================= */

static void test_delete_head_empty(void)
{
    Node *head = NULL;

    head = delete_at_head(head);

    assert(head == NULL);

    printf("PASS: delete_head_empty\n");
}

static void test_delete_head(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    head = delete_at_head(head);

    int expected[] = {20, 30};

    assert_list(head, expected, 2);

    free_list(head);

    printf("PASS: delete_head\n");
}

static void test_delete_head_single(void)
{
    int values[] = {10};

    Node *head = make_list(values, 1);

    head = delete_at_head(head);

    assert(head == NULL);

    printf("PASS: delete_head_single\n");
}

/* =========================================================
 * delete_at_tail
 * ========================================================= */

static void test_delete_tail_empty(void)
{
    Node *head = NULL;

    head = delete_at_tail(head);

    assert(head == NULL);

    printf("PASS: delete_tail_empty\n");
}

static void test_delete_tail_single(void)
{
    int values[] = {10};

    Node *head = make_list(values, 1);

    head = delete_at_tail(head);

    assert(head == NULL);

    printf("PASS: delete_tail_single\n");
}

static void test_delete_tail(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    head = delete_at_tail(head);

    int expected[] = {10, 20};

    assert_list(head, expected, 2);

    free_list(head);

    printf("PASS: delete_tail\n");
}

/* =========================================================
 * delete_first_match
 * ========================================================= */

static void test_delete_first_match(void)
{
    int values[] = {10, 20, 20, 30};

    Node *head = make_list(values, 4);

    bool deleted = false;

    head = delete_first_match(head, 20, &deleted);

    assert(deleted == true);

    int expected[] = {10, 20, 30};

    assert_list(head, expected, 3);

    free_list(head);

    printf("PASS: delete_first_match\n");
}

static void test_delete_first_match_not_found(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    bool deleted = false;

    head = delete_first_match(head, 99, &deleted);

    assert(deleted == false);

    int expected[] = {10, 20, 30};

    assert_list(head, expected, 3);

    free_list(head);

    printf("PASS: delete_first_match_not_found\n");
}

static void test_delete_first_match_head(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    bool deleted = false;

    head = delete_first_match(head, 10, &deleted);

    assert(deleted == true);

    int expected[] = {20, 30};

    assert_list(head, expected, 2);

    free_list(head);

    printf("PASS: delete_first_match_head\n");
}

/* =========================================================
 * delete_all_matches
 * ========================================================= */

static void test_delete_all_matches(void)
{
    int values[] = {10, 20, 20, 30, 20};

    Node *head = make_list(values, 5);

    int num_deleted = 0;

    head = delete_all_matches(head, 20, &num_deleted);

    assert(num_deleted == 3);

    int expected[] = {10, 30};

    assert_list(head, expected, 2);

    free_list(head);

    printf("PASS: delete_all_matches\n");
}

static void test_delete_all_matches_not_found(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    int num_deleted = 0;

    head = delete_all_matches(head, 99, &num_deleted);

    assert(num_deleted == 0);

    int expected[] = {10, 20, 30};

    assert_list(head, expected, 3);

    free_list(head);

    printf("PASS: delete_all_matches_not_found\n");
}

static void test_delete_all_matches_everything(void)
{
    int values[] = {20, 20, 20};

    Node *head = make_list(values, 3);

    int num_deleted = 0;

    head = delete_all_matches(head, 20, &num_deleted);

    assert(num_deleted == 3);
    assert(head == NULL);

    printf("PASS: delete_all_matches_everything\n");
}

/* =========================================================
 * efficient_delete_match
 * ========================================================= */

static void test_efficient_delete_match(void)
{
    int values[] = {20, 20, 10, 20, 30, 20};

    Node *head = make_list(values, 6);

    int num_deleted = 0;

    head = efficient_delete_match(head, 20, &num_deleted);

    assert(num_deleted == 4);

    int expected[] = {10, 30};

    assert_list(head, expected, 2);

    free_list(head);

    printf("PASS: efficient_delete_match\n");
}

static void test_efficient_delete_match_all(void)
{
    int values[] = {20, 20, 20};

    Node *head = make_list(values, 3);

    int num_deleted = 0;

    head = efficient_delete_match(head, 20, &num_deleted);

    assert(num_deleted == 3);
    assert(head == NULL);

    printf("PASS: efficient_delete_match_all\n");
}

/* =========================================================
 * reverse
 * ========================================================= */

static void test_reverse(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    head = reverse_list(head);

    int expected[] = {30, 20, 10};

    assert_list(head, expected, 3);

    free_list(head);

    printf("PASS: reverse\n");
}

static void test_reverse_empty(void)
{
    Node *head = NULL;

    head = reverse_list(head);

    assert(head == NULL);

    printf("PASS: reverse_empty\n");
}

/* =========================================================
 * length
 * ========================================================= */

static void test_length(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    assert(list_length(head) == 3);

    free_list(head);

    printf("PASS: length\n");
}

/* =========================================================
 * contains
 * ========================================================= */

static void test_contains(void)
{
    int values[] = {10, 20, 30};

    Node *head = make_list(values, 3);

    assert(list_contains(head, 20) == true);
    assert(list_contains(head, 99) == false);

    free_list(head);

    printf("PASS: contains\n");
}

/* =========================================================
 * Main
 * ========================================================= */

int main(void)
{
    test_insert_at_head_empty();
    test_insert_at_head();

    test_insert_at_tail_empty();
    test_insert_at_tail();

    test_delete_head_empty();
    test_delete_head();
    test_delete_head_single();

    test_delete_tail_empty();
    test_delete_tail_single();
    test_delete_tail();

    test_delete_first_match();
    test_delete_first_match_not_found();
    test_delete_first_match_head();

    test_delete_all_matches();
    test_delete_all_matches_not_found();
    test_delete_all_matches_everything();

    test_efficient_delete_match();
    test_efficient_delete_match_all();

    test_reverse();
    test_reverse_empty();

    test_length();
    test_contains();

    printf("\nALL TESTS PASSED\n");

    return 0;
}
