#include <vector>
using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
      p.push_back({target - position[i], speed[i]});
    }
    sort(p.begin(), p.end());
    int count = 0;
    double prev = 0;
    for (int i = 0; i < n; i++) {

      double time = (double)p[i].first / p[i].second;
      if (time <= prev) {
        continue;
      } else {
        count++;
        prev = time;
      }
    }
    return count;
  }
};