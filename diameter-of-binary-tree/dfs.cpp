#include <algorithm>
#include <climits>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * Helper function to compute the height of the tree while updating the 
     * maximum diameter found so far.
     * 
     * @param root The current root node of the subtree.
     * @param mx Reference to the variable tracking the maximum diameter.
     * @return The height of the current subtree.
     */
    int treeHeight(TreeNode* root, int& mx) {
        // Base case: An empty tree has a height of 0.
        if (root == nullptr) return 0;
        
        // Recursively compute the height of left and right subtrees
        int left = treeHeight(root->left, mx);
        int right = treeHeight(root->right, mx);
        
        // The diameter passing through the current node is the sum of the heights
        // of its left and right subtrees. Update the global maximum diameter.
        mx = max(mx, left + right);
        
        // Return the height of the current subtree
        return max(left, right) + 1;
    }

    /**
     * Main function to compute the diameter of the binary tree.
     * The diameter of a binary tree is the length of the longest path between 
     * any two nodes in a tree. This path may or may not pass through the root.
     */
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = INT_MIN;
        treeHeight(root, mx);
        
        // Return 0 if the tree is empty (mx remains INT_MIN), otherwise return mx
        return mx == INT_MIN ? 0 : mx; 
    }
};
