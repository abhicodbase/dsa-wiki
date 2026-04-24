#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    // Queue stores pairs of (current_node, path_to_current_node)
    queue<pair<int, vector<int>>> q;
    vector<vector<int>> result;
    
    // Start from the source node (node 0) with the initial path containing only 0
    q.push({0, {0}});
    
    // Perform standard BFS
    while (!q.empty()) {
      pair<int, vector<int>> p;
      p = q.front();
      q.pop();
      
      // If we reached the target node (n - 1), add the path to the result
      if (p.first == graph.size() - 1) {
        result.push_back(p.second);
      }
      
      // Explore all adjacent neighbors of the current node
      for (auto it = graph[p.first].begin(); it != graph[p.first].end(); it++) {
        // Create a new path by appending the neighbor to the current path
        vector<int> newPath = p.second;
        newPath.push_back(*it);
        
        // Push the neighbor and the new path to the queue for further exploration
        q.push({*it, newPath});
      }
    }
    
    return result;
  }
};