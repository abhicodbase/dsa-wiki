/*
 * Longest Increasing Subsequence - Top-down Memoization (Recursion + DP)
 * Time Complexity: O(N^2)
 * Space Complexity: O(N^2)
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to find the length of LIS starting from 'idx' with 'prevIdx' as the index of the previous element in the LIS.
    int longIncSubsequence(int idx, int prevIdx, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case: if we have reached the end of the array, return 0.
        if (idx >= nums.size()) return 0;
        
        // If prevIdx is -1, we cannot use the memoization table since coordinate indices must be non-negative.
        if (prevIdx == -1) {
            // We have two choices:
            // 1. Take the current element: 1 + recurse with prevIdx set to current idx.
            // 2. Skip the current element: recurse with prevIdx unchanged.
            return max(1 + longIncSubsequence(idx + 1, idx, nums, dp), longIncSubsequence(idx + 1, prevIdx, nums, dp));
        }
        
        // Return cached result if already calculated
        if (dp[idx][prevIdx] != -1) return dp[idx][prevIdx];
        
        // If the current element is not strictly greater than the previous element, we must skip it.
        if (nums[idx] <= nums[prevIdx]) {
            return dp[idx][prevIdx] = longIncSubsequence(idx + 1, prevIdx, nums, dp);
        }
        
        // Otherwise, we take the maximum of taking or skipping the current element.
        return dp[idx][prevIdx] = max(1 + longIncSubsequence(idx + 1, idx, nums, dp), longIncSubsequence(idx + 1, prevIdx, nums, dp));
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // 2D memoization table: dp[idx][prevIdx]
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return longIncSubsequence(0, -1, nums, dp);
    }
};
