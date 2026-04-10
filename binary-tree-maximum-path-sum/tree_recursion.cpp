#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  /**
   * Recursive function to compute the maximum path starting from a node
   * and going down into one of its children's subtrees.
   */
  int maxSum(TreeNode *node, int *mx) {
    // Base case: if node is null, contribution is 0
    if (node == nullptr) {
      return 0;
    }

    // Recursively find the max path from left and right children
    int leftChildMax = maxSum(node->left, mx);
    int rightChildMax = maxSum(node->right, mx);

    // Case 1 & 2: The maximum path that can be extended to the parent.
    // It's either the node itself, or the node plus the max of its left or
    // right child.
    int currentNodeMaxVal = -100000;
    // Extend path through either branch, or just take the node value
    currentNodeMaxVal =
        max(currentNodeMaxVal, max(leftChildMax, rightChildMax) + node->val);
    currentNodeMaxVal = max(currentNodeMaxVal, node->val);

    // Update the global maximum (mx)
    // Option A: The path could end at the current node's extendable path.
    *mx = max(*mx, currentNodeMaxVal);
    // Option B: The path could cross through this node (left child + node +
    // right child).
    *mx = max(*mx, leftChildMax + rightChildMax + node->val);

    return currentNodeMaxVal;
  }

  int maxPathSum(TreeNode *root) {
    int mx = -10000; // Initialize global max with a very small value
    maxSum(root, &mx);
    return mx;
  }
};
