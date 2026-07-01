/*
 * Longest Increasing Subsequence - Patience Sorting (Binary Search)
 * Time Complexity: O(N log N)
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
        
        // tails[i] stores the smallest tail of all increasing subsequences of length i+1 found so far.
        vector<int> tails;
        
        for (int x : nums) {
            // Find the insertion position of x in the tails array using binary search (lower_bound)
            auto it = lower_bound(tails.begin(), tails.end(), x);
            
            // If x is larger than all elements in tails, append it (extends the LIS length)
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                // Otherwise, replace the first element that is >= x with x (minimizes tail value for length)
                *it = x;
            }
        }
        
        return tails.size();
    }
};
