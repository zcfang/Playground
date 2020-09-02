#include <assert.h>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
                                                        left(left),
                                                        right(right) {}
 };
 

/**
 * Problem from LeetCode 285: Inorder Successor in BST. You can find the
 * problem
 * <a href="https://leetcode.com/problems/inorder-successor-in-bst/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] p: Node within binary tree
 * @returns In order successor to node `p`
 */
TreeNode* inorder_successor(TreeNode *root, TreeNode *p);

/**
 * Finds in order successor to node `p`
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] p: Node within binary tree
 * @param[in,out] found: True if node `p` is found
 * @returns In order successor to node `p`
 */
TreeNode* find_successor(TreeNode *root, TreeNode *p, bool &found);

int main(int argc, char const *argv[]) {

    return 0;
}

TreeNode* find_successor(TreeNode *root, TreeNode *p, bool &found) {
    TreeNode *successor = nullptr;

    if (root) {
        successor = find_successor(root->left, p, found);
        if (root == p)
            found = true;
        if (found && !successor && root->val > p->val) {
            successor = root;
            return successor;
        }
        if (found && successor)
            return successor;
        successor = find_successor(root->right, p, found);
        
    }

    return successor;
}

TreeNode* inorder_successor(TreeNode *root, TreeNode *p) {
    bool found = false;
    return find_successor(root, p, found);
}
