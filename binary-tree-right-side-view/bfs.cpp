/**
 * Binary Tree Right Side View (BFS Approach)
 * 
 * Problem: Given the root of a binary tree, imagine yourself standing on the right side of it.
 * Return the values of the nodes you can see ordered from top to bottom.
 * 
 * Approach:
 * - We perform a Breadth-First Search (BFS) / Level-Order Traversal using a queue.
 * - At each level, the last node we process is the rightmost node of that level.
 * - This rightmost node is exactly what's visible from the right-side view.
 * - For each level:
 *   - We determine the number of nodes (`qSize`) currently in the queue.
 *   - We loop through all `qSize` nodes of the level.
 *   - The node at index `i == qSize - 1` is the rightmost node of the level. We capture its value.
 *   - We push the non-null left and right children into the queue for the next level.
 * - We add the captured rightmost node's value to our `result` vector.
 * 
 * Complexity:
 * - Time Complexity: O(N) where N is the total number of nodes in the binary tree, as we visit each node exactly once.
 * - Space Complexity: O(W) = O(N) where W is the maximum width of the binary tree, which determines the maximum size of the BFS queue. In the worst case (a perfect binary tree), the queue will hold up to N/2 leaf nodes.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        // Base Case: If the tree is empty, return an empty vector.
        if (root == nullptr) return result;
        
        // Queue to store nodes for level-by-level BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int qSize = q.size();
            
            // Traverse all nodes at the current level
            for (int i = 0; i < qSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                // If it is the last node in the current level, it is visible from the right side.
                if (i == qSize - 1) {
                    result.push_back(curr->val);
                }
                
                // Push children to the queue for the next level
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }
        
        return result;
    }
};