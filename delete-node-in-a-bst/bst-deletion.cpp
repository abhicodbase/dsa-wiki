/*
 * LeetCode #450 — Delete Node in a BST
 * https://leetcode.com/problems/delete-node-in-a-bst/
 *
 * APPROACH: Recursive BST Deletion
 * ──────────────────────────────────────────────────────────────
 * Delete a node from a Binary Search Tree (BST) using recursion. The algorithm proceeds as follows:
 * 1. Search for the node:
 *    - If key is smaller than root->val, search left.
 *    - If key is larger than root->val, search right.
 * 2. Delete the node when found:
 *    - Case 1: Node has no left child. Return the right child (and delete the current node to avoid memory leaks).
 *    - Case 2: Node has no right child. Return the left child (and delete the current node to avoid memory leaks).
 *    - Case 3: Node has two children. Find the inorder successor (smallest node in the right subtree), 
 *      replace the root's value with the successor's value, and delete the successor from the right subtree.
 *
 * TIME  : O(H) — Where H is the height of the BST (O(log N) for balanced trees, O(N) for skewed trees).
 * SPACE : O(H) — Recursion stack frame depth bounded by the tree height.
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
    /**
     * Deletes a node with the specified key from the Binary Search Tree.
     * 
     * @param root The root node of the BST.
     * @param key The key value of the node to delete.
     * @return The root node of the modified BST.
     */
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: key not found in the tree
        if (root == nullptr) {
            return nullptr;
        }
        
        // Search phase: navigate the tree based on BST properties
        if (key < root->val) {
            // Key is smaller, search in the left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Key is larger, search in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Deletion phase: found the node to delete!
            
            // Case 1: Node has only a right child or no children
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; // Avoid memory leaks in C++
                return temp;
            }
            
            // Case 2: Node has only a left child
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root; // Avoid memory leaks in C++
                return temp;
            }
            
            // Case 3: Node has two children
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* curr = root->right;
            while (curr->left) {
                curr = curr->left;
            }
            
            // Copy the successor's value to the current root
            root->val = curr->val;
            
            // Delete the inorder successor node from the right subtree
            root->right = deleteNode(root->right, curr->val);
        }
        
        return root;
    }
};

/*
 * ALTERNATIVE: Iterative Deletion
 * ──────────────────────────────
 * Deletion can be performed iteratively without recursion stack overhead, using pointers to pointers 
 * or tracking the parent node to relink pointers.
 *
 *   TreeNode* deleteNode(TreeNode* root, int key) {
 *       TreeNode** curr = &root;
 *       while (*curr && (*curr)->val != key) {
 *           if (key < (*curr)->val) curr = &(*curr)->left;
 *           else curr = &(*curr)->right;
 *       }
 *       if (*curr) {
 *           TreeNode* toDelete = *curr;
 *           if (!toDelete->left) *curr = toDelete->right;
 *           else if (!toDelete->right) *curr = toDelete->left;
 *           else {
 *               TreeNode** succ = &toDelete->right;
 *               while ((*succ)->left) succ = &(*succ)->left;
 *               toDelete->val = (*succ)->val;
 *               TreeNode* temp = *succ;
 *               *succ = (*succ)->right;
 *               delete temp;
 *               return root;
 *           }
 *           delete toDelete;
 *       }
 *       return root;
 *   }
 *
 * Trade-off vs current approach: The iterative approach runs in O(1) auxiliary space,
 * avoiding the O(H) recursion call stack. However, pointer-to-pointer manipulation is 
 * more complex to write and read.
 *
 * ALTERNATIVE SUCCESSOR STRATEGY:
 * ───────────────────────────────
 * Instead of using the inorder successor (minimum of the right subtree), you can also use 
 * the inorder predecessor (maximum of the left subtree). The complexity and correctness remain 
 * identical, but it might lead to slightly different tree structures after multiple deletions.
 */
