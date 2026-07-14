/*
 * LeetCode #347 — Top K Frequent Elements (Bucket Sort Approach)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        // Count frequencies of each number
        for (int num : nums) {
            mp[num]++;
        }
        
        // Create buckets where bucket[i] stores numbers that have frequency i.
        // The maximum possible frequency is N (if all elements are identical).
        vector<vector<int>> buckets(n + 1);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        // Traverse the buckets from highest frequency (n) down to lowest (0)
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }
        
        return result;
    }
};
