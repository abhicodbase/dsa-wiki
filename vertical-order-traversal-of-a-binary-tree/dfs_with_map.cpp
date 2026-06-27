/*
 * Vertical Order Traversal of a Binary Tree - DFS with Map & Sorting
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  // DFS helper function to traverse the tree and annotate each node with its (row, col) coordinates.
  // The map 'mp' automatically keeps the columns sorted from left to right (negative to positive).
  void traversal(TreeNode *node, int row, int col,
                 map<int, vector<pair<int, int>>> &mp) {
    if (node == NULL)
      return;
    
    // Store coordinate information as {row, value} under key 'col'
    mp[col].push_back({row, node->val});
    
    // Recurse on left child: row increases by 1, column decreases by 1
    traversal(node->left, row + 1, col - 1, mp);
    // Recurse on right child: row increases by 1, column increases by 1
    traversal(node->right, row + 1, col + 1, mp);
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> v;
    map<int, vector<pair<int, int>>> mp;
    
    // Traverse the tree starting from root at (0, 0)
    traversal(root, 0, 0, mp);
    
    // Process columns in sorted order (left to right)
    for (auto it = mp.begin(); it != mp.end(); it++) {
      vector<pair<int, int>> nodes = (*it).second;
      
      // Sort nodes in the current column.
      // C++ sort on pair<int, int> sorts by first element (row) first.
      // If rows are equal, it automatically sorts by second element (value).
      sort(nodes.begin(), nodes.end());
      
      vector<int> nv;
      for (auto kt = nodes.begin(); kt != nodes.end(); kt++)
        nv.push_back((*kt).second);
      v.push_back(nv);
    }
    return v;
  }
};