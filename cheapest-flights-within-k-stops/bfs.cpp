#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < flights.size(); i++) {
      pair<int, int> p = {flights[i][1], flights[i][2]};
      mp[flights[i][0]].push_back(p);
    }
    map<int, int> price;
    queue<pair<int, int>> q;
    q.push({src, 0});
    int cnt = 0;
    while (!q.empty()) {
      int sze = q.size();
      if (cnt > k)
        break;
      cnt++; // tracking levels.....
      for (int i = 0; i < sze; i++) {
        pair<int, int> node = q.front();
        q.pop();
        vector<pair<int, int>> path = mp[node.first];
        for (auto it = path.begin(); it != path.end(); it++) {
          int currentCost = (*it).second + node.second;
          bool isUpdateRequired = true;
          if (price.find((*it).first) != price.end()) {
            if (price[(*it).first] <= currentCost)
              isUpdateRequired = false;
          }
          if (isUpdateRequired) {
            q.push({(*it).first, currentCost});
            price[(*it).first] = currentCost;
          }
        }
      }
    }
    if (price.find(dst) == price.end()) {
      return -1;
    }
    return price[dst];
  }
};