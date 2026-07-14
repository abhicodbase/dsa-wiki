/*
 * LeetCode #347 — Top K Frequent Elements (Min-Heap Approach)
 * Time Complexity: O(N log K) where N is the number of elements
 * Space Complexity: O(N) to store frequencies in the hash map
 */
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count element frequencies using a hash map
        unordered_map <int, int> mp;
        for(auto it = nums.begin(); it != nums.end(); it++) {
            mp[*it]++;
        }
        
        // Step 2: Use a min-heap to keep track of the K most frequent elements.
        // We use greater<pair<int,int>> to order pairs by frequency ascending.
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // Push {frequency, value} pair
            pq.push({(*it).second, (*it).first});
            
            // If heap size exceeds K, remove the element with the lowest frequency
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 3: Extract elements from the heap into our result array
        vector<int> freqElement;
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            freqElement.push_back(p.second);
        }
        
        return freqElement;
    }
};
