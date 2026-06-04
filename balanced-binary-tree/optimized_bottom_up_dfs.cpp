#include <algorithm>
#include <cmath>
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
     * Helper function that returns the height of the tree if it is balanced,
     * or -1 if any subtree is found to be unbalanced (early-termination).
     * 
     * @param root The current root node of the subtree.
     * @return The height of the subtree, or -1 if unbalanced.
     */
    int checkHeight(TreeNode* root) {
        // Base case: An empty tree is balanced and has a height of 0.
        if (root == nullptr) return 0;
        
        // Recursively check the left subtree
        int leftHeight = checkHeight(root->left);
        // If the left subtree is unbalanced, propagate the -1 upwards immediately
        if (leftHeight == -1) return -1;
        
        // Recursively check the right subtree
        int rightHeight = checkHeight(root->right);
        // If the right subtree is unbalanced, propagate the -1 upwards immediately
        if (rightHeight == -1) return -1;
        
        // If the current node violates the balance factor, return -1 (unbalanced)
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // Otherwise, return the actual height of the current subtree
        return max(leftHeight, rightHeight) + 1;
    }

    /**
     * Main function to determine if a binary tree is height-balanced.
     * A binary tree is balanced if the depth of the two subtrees of every node 
     * never differs by more than 1.
     */
    bool isBalanced(TreeNode* root) {
        // The tree is balanced if checkHeight does not return -1
        return checkHeight(root) != -1;
    }
};
