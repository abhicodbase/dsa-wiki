#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dfs(int source, const vector<vector<int>>& adj, const string& s, int& ans) {
        int best1 = 0; // Longest valid path from a child
        int best2 = 0; // Second longest valid path from a child

        for (int child : adj[source]) {
            // Recursively find the longest path starting at the child
            int childLen = dfs(child, adj, s, ans);
            
            // A path cannot continue if the adjacent characters are the same
            if (s[source] == s[child]) {
                continue;
            }
            
            // Keep track of the top two longest paths from children
            if (childLen > best1) {
                best2 = best1;
                best1 = childLen;
            } else if (childLen > best2) {
                best2 = childLen;
            }
        }
        
        // Update the global maximum path length:
        // Combined path: best1 + best2 + 1 (the current node acts as the turning point)
        ans = max(ans, best1 + best2 + 1);
        
        // Return the longest single path extending down from the current node
        return best1 + 1;
    }   

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        
        // Using vector<vector<int>> instead of unordered_map is faster and saves memory
        // since node labels are contiguous integers from 0 to n-1.
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }
        
        int ans = 1;
        dfs(0, adj, s, ans);
        return ans;
    }
};
