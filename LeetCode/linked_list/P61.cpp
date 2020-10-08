#include <assert.h>

/**
 * Definition for a singly-linked list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Problem from LeetCode 61: Rotate List. You can find the
 * problem <a href="https://leetcode.com/problems/rotate-list/">
 * here</a>.
 *
 * @param[in] head: The head of a singly-linked list
 * @param[in] k: A non-negative number
 * @returns The head of a list rotated to the right by k places
 */
ListNode* rotate_right(ListNode *head, int k);

int main(int argc, char const *argv[]) {

    return 0;
}

ListNode* rotate_right(ListNode *head, int k) {
    if (!head) return head;
    ListNode *begin = head;
    ListNode *end = head;
    ListNode *output;
    int size = 1;

    while (end->next) {
        end = end->next;
        size++;
    }
    k %= size;
    end->next = head;
    for (int i = 0; i < size - k - 1; i++) {
        begin = begin->next;
    }
    output = begin->next;
    begin->next = nullptr;

    return output;
}
