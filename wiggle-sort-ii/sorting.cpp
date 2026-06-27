/*
 * Wiggle Sort II - Sorting Approach
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Create a copy of the original array and sort it
        vector<int> v = nums;
        sort(v.begin(), v.end());
        
        // Set pointers to the end of the smaller and larger halves.
        // Left half (smaller elements): v[0...mid]
        // Right half (larger elements): v[mid+1...n-1]
        int end = n - 1;
        int mid = (n - 1) / 2;    
        
        // Reconstruct nums by interlacing the elements:
        // Even indices get values from the smaller half (descending)
        // Odd indices get values from the larger half (descending)
        // Placing them in reverse order prevents equal elements from being adjacent.
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = v[mid--];
            } else {
                nums[i] = v[end--];
            }
        } 
        return;
    }
};
