/*
 * Course Schedule - BFS (Kahn's Algorithm)
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */
#include <queue>
#include <vector>

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> indegree(numCourses, 0);
    for (auto &pre : prerequisites) {
      adj[pre[1]].push_back(pre[0]);
      indegree[pre[0]]++;
    }

    std::queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      count++;
      for (int next : adj[curr]) {
        if (--indegree[next] == 0)
          q.push(next);
      }
    }
    return count == numCourses;
  }
};
