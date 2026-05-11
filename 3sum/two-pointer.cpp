class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
      // Skip duplicate pivot
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      // Optimization: if smallest possible sum > 0, no solution
      if (nums[i] > 0)
        break;

      int left = i + 1, right = n - 1;
      int target = -nums[i];

      while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
          result.push_back({nums[i], nums[left], nums[right]});

          // Skip duplicates
          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;

          left++;
          right--;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return result;
  }
};