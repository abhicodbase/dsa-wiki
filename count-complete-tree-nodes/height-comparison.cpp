/*
 * LeetCode #222 — Count Complete Tree Nodes
 * Time Complexity: O(log² N)
 * Space Complexity: O(log N)
 */
#include <iostream>
#include <cmath>

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
    int getHeight(TreeNode* node) {
        if(node == NULL) return 0;
        
        TreeNode* leftNode = node;
        int leftHeight = 0, rightHeight = 0;
        
        // Find left-most height
        while(leftNode != NULL) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        
        // Find right-most height
        TreeNode* rightNode = node;
        while(rightNode != NULL) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        
        // If left and right heights are equal, the tree is a perfect binary tree
        if(leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        
        // Otherwise, recurse on left and right subtrees
        return 1 + getHeight(node->left) + getHeight(node->right);
    }
    
    int countNodes(TreeNode* root) {
        return getHeight(root);
    }
};
