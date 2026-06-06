#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @brief Definition for a binary tree node.
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/**
 * @brief Solution class to find all nodes at distance K from a target node
 *        in a binary tree.
 *
 * The approach consists of two phases:
 *   1. **Parent Mapping** – Perform a DFS to record each node's parent in an
 *      unordered_map keyed by the node's value. This enables upward traversal
 *      from any node.
 *   2. **Breadth‑First Search** – Starting from the target node, run a BFS
 *      that expands to left child, right child, and parent (if not visited).
 *      The BFS stops after `k` levels, and the remaining nodes in the queue are
 *      exactly those at distance `k`.
 *
 * Both phases run in O(N) time and use O(N) extra space, where N is the number
 * of nodes in the tree.
 */
class Solution {
public:
  /**
   * @brief Populates a map from node value to its parent pointer.
   *
   * @param root Current subtree root.
   * @param mp   Reference to the map being filled.
   */
  void getParentMap(TreeNode *root, unordered_map<int, TreeNode *> &mp) {
    if (root == nullptr)
      return;
    if (root->left != nullptr) {
      mp[root->left->val] = root; // left child's parent is current node
    }
    getParentMap(root->left, mp);
    if (root->right != nullptr) {
      mp[root->right->val] = root; // right child's parent is current node
    }
    getParentMap(root->right, mp);
  }

  /**
   * @brief Performs a BFS from `target` to collect all nodes exactly `k`
   *        edges away.
   *
   * @param target Starting node.
   * @param mp     Map of child value to parent pointer.
   * @param k      Desired distance.
   * @return vector<int> List of node values at distance `k` (order does not
   *                     matter).
   */
  vector<int> getkdistancenode(TreeNode *target,
                               unordered_map<int, TreeNode *> &mp, int k) {
    vector<int> result;
    if (target == nullptr)
      return result;

    queue<TreeNode *> q;
    q.push(target);
    unordered_map<int, bool> visited; // tracks visited node values
    visited[target->val] = true;
    int currentDist = 0;

    while (!q.empty()) {
      int sz = q.size();
      if (currentDist == k)
        break; // reached required distance
      ++currentDist;
      for (int i = 0; i < sz; ++i) {
        TreeNode *node = q.front();
        q.pop();
        // Explore left child
        if (node->left && !visited[node->left->val]) {
          visited[node->left->val] = true;
          q.push(node->left);
        }
        // Explore right child
        if (node->right && !visited[node->right->val]) {
          visited[node->right->val] = true;
          q.push(node->right);
        }
        // Explore parent via map
        if (mp.find(node->val) != mp.end()) {
          TreeNode *parent = mp[node->val];
          if (!visited[parent->val]) {
            visited[parent->val] = true;
            q.push(parent);
          }
        }
      }
    }
    // Remaining nodes in queue are exactly at distance k
    while (!q.empty()) {
      result.push_back(q.front()->val);
      q.pop();
    }
    return result;
  }

  /**
   * @brief Entry point required by LeetCode – builds the parent map and
   *        delegates to the BFS helper.
   *
   * @param root   Root of the binary tree.
   * @param target Target node whose distance‑K neighbors are sought.
   * @param k      Desired distance.
   * @return vector<int> Nodes at distance `k` from `target`.
   */
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<int, TreeNode *> parentMap;
    getParentMap(root, parentMap); // populate parent relationships
    return getkdistancenode(target, parentMap, k);
  }
};
