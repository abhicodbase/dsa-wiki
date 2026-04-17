#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // Base Case 1: If we reach the end of a branch, return nullptr.
    // Base Case 2: If we find either of the target nodes (p or q),
    // we return the current node. This propagates the found node up the
    // recursive stack.
    if (root == nullptr || root == p || root == q) {
      return root;
    }

    // Recursively search for p and q in the left and right subtrees.
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // If both left and right return non-null, it means p and q are found in
    // different subtrees of the current root. Therefore, the current root MUST
    // be their Lowest Common Ancestor.
    if (left != nullptr && right != nullptr) {
      return root;
    }

    // If only one subtree returns a non-null node, it means both p and q are
    // located in that same subtree (or we only found one of them so far).
    // In either case, we propagate the non-null result upwards.
    // If both are null, it naturally returns null.
    return left != nullptr ? left : right;
  }
};