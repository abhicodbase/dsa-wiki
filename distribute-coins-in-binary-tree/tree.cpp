#include <iostream>
#include <cmath>

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
     * Helper function to calculate the excess coins available in a subtree.
     * 
     * The core idea is that for any subtree, the number of moves needed to balance 
     * its children and itself is the absolute sum of the "excess" coins that must 
     * enter or leave those subtrees.
     * 
     * @param root The current node
     * @param moves A reference to the total moves counter
     * @return The excess coins in the current subtree (positive = surplus, negative = deficit)
     */
    int extraCoinsAvailable(TreeNode *root, int &moves) {
        if (root == nullptr) {
            return 0;
        }

        // Post-order traversal: collect information from children first
        int extraLeftCoins = extraCoinsAvailable(root->left, moves);
        int extraRightCoins = extraCoinsAvailable(root->right, moves);

        // The total excess coins for this subtree is (left excess + right excess + current surplus/deficit)
        // current surplus/deficit = root->val - 1 (since we want exactly 1 coin at this node)
        int extraCoins = extraLeftCoins + extraRightCoins + (root->val - 1);

        // Every excess coin (surplus or deficit) must cross the edge between the current node 
        // and its parent or children. Each such crossing counts as a move.
        moves += std::abs(extraLeftCoins) + std::abs(extraRightCoins);

        return extraCoins;
    }

    /**
     * Main function to find the minimum number of moves to distribute coins.
     */
    int distributeCoins(TreeNode *root) {
        int moves = 0;
        extraCoinsAvailable(root, moves);
        return moves;
    }
};