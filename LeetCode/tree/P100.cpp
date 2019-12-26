#include <vector>
#include <assert.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Problem from LeetCode 100: Same Tree. You can find the
 * problem
 * <a href="https://leetcode.com/problems/same-tree/">
 * here</a>.
 *
 * @param[in] p: A tree
 * @param[in] q: A tree
 * @returns Whether p and q are the same tree
 */
bool is_same_tree(TreeNode* p, TreeNode* q);

int main(int argc, char const *argv[]) {

    return 0;
}

bool is_same_tree(TreeNode* p, TreeNode* q) {
    bool same_tree = true;
        
    if (p == NULL && q != NULL) {
        return false;
    } else if (p != NULL && q == NULL) {
        return false;
    } else if (p != NULL && q != NULL) {
        same_tree &= is_same_tree(p->left, q->left);
        same_tree &= is_same_tree(p->right, q->right);
        same_tree &= p->val == q->val;
    }

    return same_tree;
}
