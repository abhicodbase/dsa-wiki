#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> v;
    unordered_map<int, vector<int>> mp; // Adjacency list: maps course -> list of dependent courses
    unordered_map<int, int> deg;        // Indegree map: tracks the number of prerequisites for each course

    // Step 1: Build the adjacency list and populate the indegree for each course
    for (int i = 0; i < prerequisites.size(); i++) {
      mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
      
      // Initialize indegrees to 0 if not already present
      if (deg.find(prerequisites[i][0]) == deg.end())
        deg[prerequisites[i][0]] = 0;
      if (deg.find(prerequisites[i][1]) == deg.end())
        deg[prerequisites[i][1]] = 0;
      
      // Increment indegree for the dependent course
      deg[prerequisites[i][0]]++;
    }

    // Step 2: Queue courses with 0 indegree (no prerequisites)
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (deg.find(i) == deg.end()) {
        // Course does not exist in any prerequisite pair; it has 0 indegree and can be taken immediately
        v.push_back(i);
      } else {
        // If the course exists in prerequisites and has indegree 0, add it to the queue
        if (deg[i] == 0)
          q.push(i);
      }
    }

    // Step 3: BFS traversal to peel off courses one by one
    while (!q.empty()) {
      int sze = q.size();
      for (int i = 0; i < sze; i++) {
        int val = q.front();
        v.push_back(val);
        q.pop();

        // For each neighbor (dependent course), decrement its indegree
        for (auto it = mp[val].begin(); it != mp[val].end(); it++) {
          deg[*it]--;
          // If indegree becomes 0, all prerequisites are met; add it to the queue
          if (deg[*it] == 0)
            q.push(*it);
        }
      }
    }

    // Step 4: If the order contains fewer than numCourses, a cycle exists
    if (v.size() < numCourses)
      return vector<int>();

    return v;
  }
};