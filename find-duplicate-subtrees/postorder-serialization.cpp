#include <string>
#include <vector>
#include <unordered_map>

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
     * Post-order traversal to serialize each subtree and check for duplicates.
     * 
     * Serialization format: "(left,val,right)"
     * Using brackets and commas guarantees unique representation without ambiguity.
     */
    string postOrder(TreeNode* root, unordered_map<string,int>& mp, vector<TreeNode*>& v) {
        // Base case: represent empty node as '#'
        if (!root) return "#";
        
        // Post-order traversal: process left and right subtrees first
        string leftStr  = postOrder(root->left,  mp, v);
        string rightStr = postOrder(root->right, mp, v);
        
        // Combine left representation, root value, and right representation into a unique string
        string str = "(" + leftStr + "," + to_string(root->val) + "," + rightStr + ")";
        
        // Track the occurrence of this serialization in the map
        // Push the root to the results vector ONLY on the 2nd occurrence (mp[str] == 1 before increment)
        // to avoid duplicate additions of the same subtree shape.
        if (mp[str]++ == 1)
            v.push_back(root);
            
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> v;
        postOrder(root, mp, v);
        return v;
    }
};
