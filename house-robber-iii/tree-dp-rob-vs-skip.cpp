#include <algorithm>
#include <utility>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
     * Helper function performing Depth-First Search (DFS) for Tree DP.
     * 
     * Returns a pair of integers:
     * - first: The maximum money obtained if we ROB the current node.
     * - second: The maximum money obtained if we SKIP the current node.
     */
    pair<int, int> dfs(TreeNode* node) {
        // Base case: empty node returns 0 for both robbing and skipping
        if(node == NULL) {
            return {0, 0};
        }
        
        // Post-order traversal: compute values bottom-up from children
        pair<int, int> pleft = dfs(node->left);
        pair<int, int> pright = dfs(node->right);
        
        // Scenario 1: Rob the current node
        // If we rob the current node, we MUST skip both its left and right children
        int rob = node->val + pleft.second + pright.second;
        
        // Scenario 2: Skip the current node
        // If we skip the current node, we are free to either rob or skip its children.
        // We choose the maximum possible yield from each subtree.
        int skip = max(pleft.first, pleft.second) + max(pright.first, pright.second);
        
        return {rob, skip};
    }
    
    int rob(TreeNode* root) {
        // Run Tree DP starting at the root
        pair<int, int> p = dfs(root);
        
        // Return the maximum yield between robbing the root or skipping it
        return max(p.first, p.second);
    }
};
