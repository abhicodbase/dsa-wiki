#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int low = 0, high = arr.size() - k;
    while (low < high) {
      int mid = (low + high) / 2;
      if (x - arr[mid] > arr[mid + k] - x) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    vector<int> result = vector<int>(arr.begin() + low, arr.begin() + low + k);
    return result;
  }
};