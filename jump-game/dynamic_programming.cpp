/*
 * Jump Game - Dynamic Programming Approach
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // reach[i] will be true if we can reach index i
        vector<bool> reach(n, false);
        reach[0] = true; // Base case: we are already at the first index
        
        // Iterate through all indices except the last one
        for(int i=0;i<n-1;i++) {
            // If we can't reach the current index, we can't jump from it
            if(!reach[i]){
                continue;
            } 
            
            // Check all possible jump lengths from the current index i
            for(int j=1;j<=nums[i];j++) {
                int currentIndex = i+j;
                
                // If the jump takes us out of bounds, no need to check further
                if (currentIndex >= n) {
                    break;
                }
                
                // If we reach the last index directly, we can stop early
                if (currentIndex == n-1) {
                    return true;
                }
                
                // Mark the reached index as reachable
                reach[currentIndex] = true;
            }           
        }
        
        // Return whether the last index is reachable
        return reach[n-1];
    }
};
