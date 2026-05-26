/**
 * Binary Tree Level Order Traversal (BFS Approach)
 * 
 * Problem: Given the root of a binary tree, return the level order traversal of its nodes' values
 * (i.e., from left to right, level by level).
 * 
 * Approach:
 * - We use Breadth-First Search (BFS) powered by a Queue data structure to traverse level by level.
 * - To group nodes of the same level together:
 *   1. Before starting a level, we record the size of the queue (`currentItems = q.size()`).
 *   2. This size represents exactly how many nodes exist on the current level.
 *   3. We then run a loop exactly `currentItems` times to pop nodes of the current level, add their values
 *      to a temporary vector `v`, and push their non-null left and right child nodes into the queue for the next level.
 *   4. Once the inner loop finishes, we add `v` to our 2D result vector.
 * 
 * Complexity:
 * - Time Complexity: O(N) where N is the total number of nodes in the binary tree, as each node is pushed and popped from the queue exactly once.
 * - Space Complexity: O(N) auxiliary space. In the worst case (e.g., a perfect binary tree), the queue will hold up to N/2 leaf nodes at the deepest level.
 */

#include <vector>
#include <queue>
#include <cstddef>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // Base Case: If the tree is empty, return an empty list.
        if (root == NULL) return result;
        
        // Queue to store nodes for level-by-level BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int currentItems = q.size();
            vector<int> currentLevelValues;
            
            // Process all nodes at the current level
            for (int i = 0; i < currentItems; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Add the node's value to the current level's list
                currentLevelValues.push_back(node->val);
                
                // Push children of the current node to the queue (to be processed at the next level)
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right); 
                }
            }
            
            // Add the current level's values to the final result list
            result.push_back(currentLevelValues);
        }
        
        return result;
    }
};