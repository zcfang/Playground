#include <vector>
#include <assert.h>

/**
 * Definition for a singly-linked list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Creates a singly-linked list from a standard vector
 *
 * @param[in] linked_list: A standard vector with values to create linked list
 * @returns The head of a singly-linked list where the values are taken from
 * `linked_list`
 */
ListNode* create_linked_list(std::vector<int> &linked_list);

/**
 * Compares two singly-linked list and returns true if they are equivalent
 *
 * @param[in] head_1: Head of singly-linked list
 * @param[in] head_2: Heas of singly-linked list
 * @returns Returns true if both input singly-linked list are the same, false
 * otherwise. 
 */
bool same_linked_list(ListNode *head_1, ListNode *head_2);

/**
 * Problem from LeetCode 876: Middle of the Linked List. You can find the
 * problem <a href="https://leetcode.com/problems/middle-of-the-linked-list/">
 * here</a>.
 *
 * @param[in] head: The head of a singly-linked list
 * @returns The head to the middle of a singly-linked list
 */
ListNode* middle_node(ListNode *head);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3,4,5};
    std::vector<int> test_case_2{1,2,3,4,5,6};
    std::vector<int> solution_1{3,4,5};
    std::vector<int> solution_2{4,5,6};
    ListNode *linked_list_1 = create_linked_list(test_case_1);
    ListNode *linked_list_2 = create_linked_list(test_case_2);
    ListNode *solution_ll_1 = create_linked_list(solution_1);
    ListNode *solution_ll_2 = create_linked_list(solution_2);

    linked_list_1 = middle_node(linked_list_1);
    linked_list_2 = middle_node(linked_list_2);
    assert(same_linked_list(linked_list_1, solution_ll_1));
    assert(same_linked_list(linked_list_2, solution_ll_2));

    return 0;
}

ListNode* create_linked_list(std::vector<int> &linked_list) {
    ListNode *head = new ListNode(linked_list[0]);
    ListNode *temp = head;

    for (std::size_t i = 1; i < linked_list.size(); i++) {
        temp->next = new ListNode(linked_list[i]);
        temp = temp->next;
    }

    return head;
}

bool same_linked_list(ListNode *head_1, ListNode *head_2) {
    while (head_1 && head_2) {
        if (head_1->val != head_2->val) return false;
        head_1 = head_1->next;
        head_2 = head_2->next;
    }
    return true;
}

ListNode* middle_node(ListNode *head) {
    ListNode *first_ptr = head;
    ListNode *second_ptr = head;

    while (second_ptr != NULL && second_ptr->next != NULL) {
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next->next;
    }

    return first_ptr;
}
