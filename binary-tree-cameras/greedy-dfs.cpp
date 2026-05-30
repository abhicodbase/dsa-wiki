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
     * Helper function to post-order traverse the tree and track camera placements.
     * 
     * The algorithm relies on 3 key states returned by each node:
     * - State 0: The node needs a camera (it is not covered).
     * - State 1: The node has a camera installed.
     * - State 2: The node is covered (either it's NULL, or one of its children has a camera).
     * 
     * @param root The current binary tree node.
     * @param count Reference to the camera counter.
     * @return The state of the current node (0, 1, or 2).
     */
    int trackCamera(TreeNode* root, int &count) {
        // Base case: An empty node is considered covered (State 2)
        // so that it does not demand a camera from its parent.
        if (root == nullptr) {
            return 2;
        }

        // Post-order traversal: process children first
        int left = trackCamera(root->left, count);
        int right = trackCamera(root->right, count);

        // Case 1: If any child needs coverage (State 0), we MUST place a camera at this parent node.
        if (left == 0 || right == 0) {
            count++;
            return 1; // This node now has a camera (State 1)
        }

        // Case 2: If any child has a camera (State 1), this node is successfully covered.
        if (left == 1 || right == 1) {
            return 2; // This node is covered (State 2)
        }

        // Case 3: If both children are covered (State 2) but neither has a camera,
        // this node is uncovered and needs to be covered by its parent node.
        return 0; // This node needs coverage (State 0)
    }

    /**
     * Returns the minimum number of cameras needed to monitor all nodes of the tree.
     */
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int count = 0;
        
        // If the root node itself returns State 0, it has no parent to cover it.
        // Therefore, we must place a camera directly at the root.
        if (trackCamera(root, count) == 0) {
            count++;
        }

        return count;
    }
};
