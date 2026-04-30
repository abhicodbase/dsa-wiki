#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Finds the number of non-empty subarrays with a sum equal to 'goal'.
     * 
     * Approach: Prefix Sum + Hash Map
     * We maintain a running sum (prefix sum) as we iterate through the array.
     * We use a hash map to store the frequencies of all prefix sums seen so far.
     * If (current_sum - goal) exists in our map, it means there is a subarray
     * ending at the current index which sums up to 'goal'. We add the frequency
     * of (current_sum - goal) to our result.
     */
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Map to store frequency of prefix sums: {prefix_sum : count}
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        int result = 0;
        
        // Base case: A prefix sum of 0 occurs exactly once initially (before any elements)
        // This handles cases where a prefix itself from index 0 is exactly equal to 'goal'
        mp[0] = 1; 
        
        for(int i = 0; i < n; i++) {
            sum += nums[i]; // Update running prefix sum
            
            // If we have seen a prefix sum that equals (sum - goal),
            // then the subarray between that prefix and current index sums to 'goal'.
            if(mp.find(sum - goal) != mp.end()) {
                result += mp[sum - goal];
            }
            
            // Add the current prefix sum to the map for future subarrays
            mp[sum]++;
        }
        
        return result;
    }
};