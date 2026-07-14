/*
 * LeetCode #692 — Top K Frequent Words
 * Time Complexity: O(N log K) where N is the number of words
 * Space Complexity: O(N) to store word frequencies in the hash map
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Custom comparator for min-heap of size K
    struct Compare {
        bool operator() (const pair<int,string> &a, const pair<int,string> &b) {
            // If frequencies are different, we want the element with the smaller frequency 
            // at the top of the heap so that it gets popped off first when the heap size exceeds K.
            if(a.first != b.first) return a.first > b.first;
            
            // If frequencies are equal, we want the lexicographically LARGER string 
            // at the top of the heap so it gets popped first. This ensures lexicographically 
            // smaller words remain in our final K-sized heap.
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: Count the frequency of each word
        unordered_map <string, int> mp;
        for(int i = 0; i < words.size(); i++){
            if(mp.find(words[i]) != mp.end()) {
                mp[words[i]]++;
            } else {
                mp[words[i]] = 1;
            }
        }
        
        // Step 2: Maintain a min-heap of size K
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {            
            pq.push({(*it).second, (*it).first});
            // If the heap grows larger than K, pop the least frequent (or lexicographically larger) element
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 3: Extract elements from the heap
        vector<string> strs;
        while(!pq.empty()) {
            pair<int, string> p = pq.top();
            strs.push_back(p.second);
            pq.pop();
        }
        
        // Step 4: Reverse the result because a min-heap outputs elements in ascending order of frequency
        reverse(strs.begin(), strs.end());
        return strs;
    }
};
