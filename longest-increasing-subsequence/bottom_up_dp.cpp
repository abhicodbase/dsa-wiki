/*
 * Longest Increasing Subsequence - Bottom-up DP (Iterative)
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int result = 1;
        // dp[i] stores the length of the LIS ending at index i
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If nums[i] is greater than nums[j], nums[i] can extend the increasing subsequence ending at j.
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
