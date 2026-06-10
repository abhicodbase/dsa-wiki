#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> v;
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> deg;
    for (int i = 0; i < prerequisites.size(); i++) {
      mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
      if (deg.find(prerequisites[i][0]) == deg.end())
        deg[prerequisites[i][0]] = 0;
      if (deg.find(prerequisites[i][1]) == deg.end())
        deg[prerequisites[i][1]] = 0;
      deg[prerequisites[i][0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (deg.find(i) == deg.end()) {
        v.push_back(i);
      } else {
        if (deg[i] == 0)
          q.push(i);
      }
    }

    while (!q.empty()) {
      int sze = q.size();
      for (int i = 0; i < sze; i++) {
        int val = q.front();
        v.push_back(val);
        q.pop();
        for (auto it = mp[val].begin(); it != mp[val].end(); it++) {
          deg[*it]--;
          if (deg[*it] == 0)
            q.push(*it);
        }
      }
    }
    if (v.size() < numCourses)
      return vector<int>();
    return v;
  }
};