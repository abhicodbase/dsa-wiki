/*
 * LeetCode #222 — Count Complete Tree Nodes
 * https://leetcode.com/problems/count-complete-tree-nodes/
 *
 * APPROACH: Height Comparison
 * ──────────────────────────────────────────────────────────────
 * Determine the left-most and right-most heights of the tree.
 * If they are equal, the tree is a perfect binary tree, and its 
 * node count is 2^h - 1. Otherwise, we recurse on the left and 
 * right subtrees, adding 1 for the root node.
 * Since at least one subtree of a complete binary tree is always
 * perfect, the height comparison succeeds on one side at each step,
 * reducing recursion paths.
 *
 * TIME  : O(log² N) — computing heights takes O(log N) at each level, and we descend O(log N) times.
 * SPACE : O(log N)  — recursion stack depth is proportional to tree height.
 */

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        // Base case: An empty tree has 0 nodes.
        if (root == nullptr) {
            return 0;
        }

        TreeNode* leftNode = root;
        int leftHeight = 0;
        // Traverse along the left-most path to find the left height.
        while (leftNode != nullptr) {
            leftHeight++;
            leftNode = leftNode->left;
        }

        TreeNode* rightNode = root;
        int rightHeight = 0;
        // Traverse along the right-most path to find the right height.
        while (rightNode != nullptr) {
            rightHeight++;
            rightNode = rightNode->right;
        }

        // Key Insight: If the left-most height equals the right-most height,
        // the tree is a perfect binary tree. Its size is (2^height) - 1.
        // We use bit shifting (1 << leftHeight) to compute 2^leftHeight efficiently,
        // avoiding floating-point pow() function issues and cmath overhead.
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        // If heights differ, the last row is not full on both ends.
        // We recursively solve for left and right subtrees and add 1 for current root.
        // One of these subtrees is guaranteed to be perfect, terminating its recursion branch.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*
 * ALTERNATIVE: Naive Linear Traversal (DFS)
 * ─────────────────────────────────────────
 * A simple depth-first search visits every single node.
 *
 *   int countNodes(TreeNode* root) {
 *       if (!root) return 0;
 *       return 1 + countNodes(root->left) + countNodes(root->right);
 *   }
 *
 * Trade-off: O(N) time and O(log N) space. This is slower than O(log² N) but extremely simple to implement.
 */
