class Solution {
public:
  bool isAlreadyAvailable(vector<vector<int>> v, int a, int b, int c) {
    vector<vector<int>>::iterator it;
    vector<int> list = {a, b, c};
    sort(list.begin(), list.end());
    map<int, bool> mp;
    int count = 0;
    for (it = v.begin(); it != v.end(); it++) {
      sort((*it).begin(), (*it).end());
      if (*it == list)
        return true;
    }
    return false;
  }
  vector<vector<int>> threeSum(vector<int> &nums) {
    // brute force solution..
    vector<vector<int>> v;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            if (!isAlreadyAvailable(v, nums[i], nums[j], nums[k])) {
              v.push_back({nums[i], nums[j], nums[k]});
            }
          }
        }
      }
    }
    return v;
  }
};