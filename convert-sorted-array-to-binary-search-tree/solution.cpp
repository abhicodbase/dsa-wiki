#include <vector>
#include <cstddef>

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
    TreeNode* BSTConstruct(const vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        
        // Prevent overflow with start + (end - start)/2
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        
        // Build left and right subtrees recursively
        node->left = BSTConstruct(nums, start, mid - 1);
        node->right = BSTConstruct(nums, mid + 1, end);
        
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return BSTConstruct(nums, 0, n - 1);
    }
};
