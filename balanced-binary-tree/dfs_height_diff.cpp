#include <algorithm>
#include <climits>
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
     * Helper function to compute the height of the tree while tracking the 
     * maximum difference in height between any left and right subtrees.
     * 
     * @param root The current root node of the subtree.
     * @param mx Reference to the variable tracking the maximum height difference.
     * @return The height of the current subtree.
     */
    int treeHeight(TreeNode* root, int& mx) {
        // Base case: An empty tree has a height of 0.
        if (root == nullptr) return 0;
        
        // Recursively compute the height of left and right subtrees
        int leftDepth = treeHeight(root->left, mx);
        int rightDepth = treeHeight(root->right, mx);
        
        // Track the maximum height difference found between left and right subtrees
        mx = max(mx, abs(leftDepth - rightDepth));
        
        // Return the height of the current tree
        return max(leftDepth, rightDepth) + 1; 
    }

    /**
     * Main function to determine if a binary tree is height-balanced.
     * A binary tree is balanced if the depth of the two subtrees of every node 
     * never differs by more than 1.
     */
    bool isBalanced(TreeNode* root) {
        int mx = INT_MIN;
        treeHeight(root, mx);
        
        // If the maximum height difference between any left and right subtrees is
        // greater than 1, the tree is unbalanced.
        if (mx > 1) return false;
        return true;
    }
};
