#include <vector>
using namespace std;
class Solution {
public:
  bool canShip(vector<int> &weights, int cap, int days) {
    int weightSum = 0, dayCount = 1;
    for (int i = 0; i < weights.size(); i++) {
      if (weightSum + weights[i] > cap) {
        weightSum = 0;
        dayCount++;
      }
      weightSum += weights[i];
    }
    return dayCount <= days;
  }
  int shipWithinDays(vector<int> &weights, int days) {
    int mx = 0, sum = 0;
    for (int i = 0; i < weights.size(); i++) {
      sum += weights[i];
      mx = max(mx, weights[i]);
    }
    int low = mx, high = sum, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (canShip(weights, mid, days)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
