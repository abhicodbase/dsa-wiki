#include <iostream>
#include <map>

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
    // Helper function to map each node to its parent 
    void treeTraversal(TreeNode* root, map<TreeNode*, TreeNode*>* parentMap) {
        if(root == nullptr) {
            return;
        }
        
        // If left child exists, record its parent as the current root
        // Then recursively traverse the left subtree
        if(root->left != nullptr) {
            parentMap->insert({root->left, root});
            treeTraversal(root->left, parentMap);
        }
        
        // If right child exists, record its parent as the current root
        // Then recursively traverse the right subtree
        if(root->right != nullptr) {
            parentMap->insert({root->right, root});
            treeTraversal(root->right, parentMap);
        }
    }
    
    // Finds the lowest common ancestor of nodes p and q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Map to store child-to-parent relationships
        // The root node won't be in this map as it has no parent
        map<TreeNode*, TreeNode*> parentMap;
        treeTraversal(root, &parentMap);  
        
        // Map to keep track of all ancestors of node p (using node value as key to avoid pointer comparison issues, though pointer is also fine)
        map<int, bool> visitedParent;
        
        // Traverse upwards from node p all the way to the root
        // Mark every visited ancestor node along the path
        while(p != nullptr) {
            visitedParent[p->val] = true;
            // Move up to the parent
            p = parentMap[p]; 
        }
        
        // Traverse upwards from node q
        // The *first* node we encounter that has already been visited by p
        // is necessarily the Lowest Common Ancestor!
        while(q != nullptr) {
            if (visitedParent[q->val]) {
                return q;
            }
            // Move up to the parent
            q = parentMap[q];
        }
        
        // If no common ancestor is found (which shouldn't happen for valid inputs), return nullptr
        return nullptr;
    }
};
