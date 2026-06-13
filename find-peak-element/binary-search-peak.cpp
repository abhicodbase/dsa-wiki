#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // Binary search on monotonic slope to find any peak element
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If the element to the right is greater, we are on an ascending slope.
            // A peak must exist in the right portion (index mid+1 to high).
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } 
            // Otherwise, we are on a descending slope (or at a local peak).
            // A peak must exist at mid or in the left portion (index low to mid).
            else {
                high = mid;
            }
        }
        
        // low and high converge to a peak element index
        return high;
    }
};
