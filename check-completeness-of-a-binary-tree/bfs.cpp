#include <queue>

using namespace std;

/**
 * @brief Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/**
 * @brief Determines whether a binary tree is a complete binary tree.
 *
 * A complete binary tree has every level fully filled except possibly the last,
 * and all nodes in the last level are as far left as possible. The algorithm
 * performs a breadth‑first search (BFS) and ensures that after the first null
 * child is seen, no subsequent non‑null nodes appear.
 *
 * Time Complexity: O(N) – each node is visited once.
 * Space Complexity: O(N) – queue may hold up to one full level of nodes.
 */
class Solution {
public:
    /**
     * @param root Pointer to the root of the binary tree.
     * @return true if the tree is complete, false otherwise.
     */
    bool isCompleteTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        bool seenNull = false; // becomes true after encountering a null child
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr) {
                seenNull = true;
                continue;
            }
            if (seenNull) return false; // non‑null after null -> not complete
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};