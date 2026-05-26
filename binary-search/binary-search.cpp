/**
 * Classic Binary Search
 * 
 * Problem: Given a sorted (in ascending order) integer array `nums` and a `target` value,
 * search for `target` in `nums`. If it exists, return its index; otherwise, return -1.
 * 
 * Approach:
 * - We maintain two pointers, `low` and `high`, representing the boundaries of our current search range.
 * - In each step, we calculate the middle index `mid`.
 * - We compare `nums[mid]` with `target`:
 *   1. If `nums[mid] == target`, we have found the element and return `mid`.
 *   2. If `nums[mid] < target`, the target must be in the right half, so we narrow the range to [mid + 1, high] by setting `low = mid + 1`.
 *   3. If `nums[mid] > target`, the target must be in the left half, so we narrow the range to [low, mid - 1] by setting `high = mid - 1`.
 * - We repeat this process as long as `low <= high`. If the pointers cross and the target hasn't been found, we return -1.
 * 
 * Safe Mid Calculation:
 * - Instead of `(low + high) / 2`, we use `low + (high - low) / 2`.
 * - This prevents potential integer overflow when `low + high` exceeds the maximum capacity of a 32-bit signed integer.
 * 
 * Complexity:
 * - Time Complexity: O(log N) because the search space is divided by 2 at each step.
 * - Space Complexity: O(1) auxiliary space as it only uses a few pointers.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        
        while (low <= high) {
            // Prevent integer overflow: low + (high - low) / 2 is mathematically identical to (low + high) / 2
            mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid; // Target found
            }
            else if (nums[mid] > target) {
                high = mid - 1; // Narrow search space to the left half
            }
            else {
                low = mid + 1;  // Narrow search space to the right half
            }
        }
        
        return -1; // Target not found
    }
};