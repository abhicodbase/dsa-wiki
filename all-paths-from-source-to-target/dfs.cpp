#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int node, vector<vector<int>> &graph, vector<vector<int>> &result,
           vector<int> &path) {
    // Base condition: if we reach the target node (n - 1)
    if (node == graph.size() - 1) {
      // Add the current valid path to our result list
      result.push_back(path);
      return;
    }
    
    // Explore all adjacent neighbors of the current node
    for (auto it = graph[node].begin(); it != graph[node].end(); it++) {
      // Choose: Add the neighbor to the current path
      path.push_back(*it);
      
      // Explore: Recursively call DFS for the neighbor
      dfs(*it, graph, result, path);
      
      // Un-choose (Backtrack): Remove the neighbor from the path to explore other branches
      path.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> result;
    
    // Start from the source node (0) with the initial path containing only 0
    vector<int> v = {0};
    
    // Initiate DFS exploration
    dfs(0, graph, result, v);
    
    return result;
  }
};