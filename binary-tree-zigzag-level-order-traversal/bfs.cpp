/**
 * Binary Tree Zigzag Level Order Traversal (BFS Approach)
 * 
 * Problem: Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
 * (i.e., from left to right, then right to left for the next level and alternate between).
 * 
 * Approach:
 * - We perform a Breadth-First Search (BFS) / Level-Order Traversal using a queue.
 * - To achieve the zigzag pattern, we keep track of the current level number (or a boolean flag).
 * - For each level, we determine the number of nodes (`qSize`) currently in the queue.
 * - We allocate a vector `v` of size `qSize` for the current level's values.
 * - During iteration:
 *   - If the current level index is even, we fill the vector from left to right: `v[i] = node->val`.
 *   - If the current level index is odd, we fill the vector from right to left (i.e., reverse order): `v[qSize - 1 - i] = node->val`.
 *   - We push the child nodes (left then right) into the queue.
 * - Increment the level count after processing each level.
 * 
 * Complexity:
 * - Time Complexity: O(N) where N is the number of nodes in the binary tree, as we visit each node exactly once.
 * - Space Complexity: O(N) auxiliary space. In the worst case, the queue will store the leaf nodes of the tree, which is O(N) for a balanced tree (specifically, at most N/2 nodes at the leaf level).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // Base Case: If the tree is empty, return an empty list.
        if (root == nullptr) return result;
        
        // Queue to store nodes for level-by-level BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int qSize = q.size();
            vector<int> levelValues(qSize, 0);
            
            // Process all nodes at the current level
            for (int i = 0; i < qSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                // Determine placement based on level direction
                if (level % 2 == 0) {
                    levelValues[i] = curr->val; // Left-to-Right
                } else {
                    levelValues[qSize - 1 - i] = curr->val; // Right-to-Left
                }
                
                // Push children to the queue for the next level
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            
            // Add the current level's values to the final result list
            result.push_back(levelValues);
            
            // Toggle direction for the next level
            level++;
        }
        
        return result;
    }
};