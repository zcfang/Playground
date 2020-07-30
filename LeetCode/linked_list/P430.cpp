#include <stack>
#include <assert.h>

/**
 * Definition for a Node.
 */
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int value, Node *previous, Node *next_node, Node *child_node) {
        val = value;
        prev = previous;
        next = next_node;
        child = child_node;
    }
};

/**
 * Problem from LeetCode 430: Flatten a Multilevel Doubly Linked List. You can
 * find the problem
 * <a href="https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/">
 * here</a>.
 *
 * @param[in] head: The head of a Node
 * @returns The head of a flattened multilevel doubly linked list
 */
Node* flatten(Node* head);

int main(int argc, char const *argv[]) {

    return 0;
}

Node* flatten(Node* head) {
    if (!head) return head;
    Node *start = new Node(0, NULL, NULL, NULL);
    Node *output = start;
    std::stack<Node*> nodes;

    nodes.push(head);
    while (!nodes.empty()) {
        Node *node = nodes.top();
        nodes.pop();
        if (node->next) {
            nodes.push(node->next);
        }
        if (node->child) {
            nodes.push(node->child);
        }
        start->next = node;
        node->prev = start;
        node->child = NULL;
        start = start->next;
    }
    output = output->next;
    output->prev = NULL;

    return output;
}
