/*
 * Vertical Order Traversal of a Binary Tree - DFS with Map & Sorting
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */
#include <vector>
#include <map>
#include <algorithm>

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
    void traversal(TreeNode* node, int row, int col, std::map <int, std::vector<std::pair<int,int>>> &mp) {
        if(node == nullptr) return;
        mp[col].push_back({row, node->val});
        traversal(node->left, row + 1, col - 1, mp);
        traversal(node->right, row + 1, col + 1, mp);       
    }
    
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int>> v;
        std::map <int, std::vector<std::pair<int,int>>> mp;
        traversal(root, 0, 0, mp);
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            std::vector<std::pair<int,int>> nodes = (*it).second;
            std::sort(nodes.begin(), nodes.end());
            std::vector<int> nv;
            for(auto kt=nodes.begin(); kt != nodes.end(); kt++) nv.push_back((*kt).second); 
            v.push_back(nv);
        }
        return v;
    }
};
