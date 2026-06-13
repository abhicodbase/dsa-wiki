// LeetCode 105 — Construct Binary Tree from Preorder and Inorder Traversal
// Approach: Recursive divide-and-conquer with O(1) inorder index lookup
//
// Key insight:
//   - preorder[idx] is always the root of the current subproblem
//   - mp[rootValue] gives the root's position in inorder
//   - Elements left  of that position → left subtree  (inorder range [start, pos-1])
//   - Elements right of that position → right subtree (inorder range [pos+1, end])
//   - idx advances in preorder order (left subtree fully consumed before right)
//
// Time:  O(n) — each node visited once; map lookup O(1)
// Space: O(n) — hash map stores all n values; recursion stack O(h), h = tree height

class Solution {
public:
    int idx;                      // current position in preorder[]
    unordered_map<int, int> mp;   // inorder value → index for O(1) lookup

    TreeNode* buildBT(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;   // empty range → no node

        // Next root is always at preorder[idx]
        int rootValue = preorder[idx++];
        TreeNode* node = new TreeNode(rootValue);

        int pos = mp[rootValue];   // root's position in inorder

        // Build left subtree first — this exhausts the left portion of preorder
        node->left  = buildBT(preorder, start,   pos - 1);
        node->right = buildBT(preorder, pos + 1, end);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;
        for (int i = 0; i < (int)inorder.size(); i++)
            mp[inorder[i]] = i;

        return buildBT(preorder, 0, (int)preorder.size() - 1);
    }
};
