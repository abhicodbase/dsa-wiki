#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Monotonic Stack solution for "132 Pattern".
 * 
 * Concept:
 * - A 132 pattern consists of three indices i < j < k such that nums[i] < nums[k] < nums[j].
 * - We iterate through the array from right to left.
 * - We maintain a monotonic decreasing stack to find the "2" (the `second` highest value)
 *   and the "3" (the highest value, `nums[j]`).
 * - The `second` variable keeps track of the maximum valid `nums[k]` found so far.
 * - For each element `nums[i]`, if it is strictly less than `second`, we have found
 *   our "1" (nums[i]) < "2" (second) and previously found "3" (stack top), so we return true.
 * - If `nums[i]` is greater than the top of the stack, we pop elements from the stack
 *   and update `second` with the popped elements, ensuring `second` is always the largest
 *   element smaller than `nums[i]` (which becomes our new "3").
 * - We then push `nums[i]` onto the stack.
 * 
 * Complexity:
 * - Time: O(N) - Each element is pushed and popped from the stack at most once.
 * - Space: O(N) - In the worst case, the stack can hold up to N elements.
 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        // 'second' represents the '2' in the 132 pattern (nums[k]).
        // We initialize it to the lowest possible integer.
        int second = -1000000000; 

        // Iterate from right to left
        for(int i = nums.size() - 1; i >= 0; i--) {
            // If we find an element smaller than 'second', we found our '1' (nums[i]).
            // Since we iterate right to left, nums[i] comes before the element that
            // set 'second', satisfying the i < j < k condition.
            if(nums[i] < second) {
                return true;
            }

            // Maintain the monotonic decreasing stack.
            // If the current element is greater than the top of the stack,
            // it can potentially be the '3' (nums[j]) for elements currently in the stack.
            // We pop smaller elements and update 'second' (which becomes nums[k]).
            while(!stk.empty() && nums[i] > stk.top()) {
                second = stk.top();
                stk.pop();
            }

            // Push the current element onto the stack
            stk.push(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Example 1 (1, 2, 3, 4): " << (sol.find132pattern(nums1) ? "true" : "false") << endl;
    // Expected: false
    
    vector<int> nums2 = {3, 1, 4, 2};
    cout << "Example 2 (3, 1, 4, 2): " << (sol.find132pattern(nums2) ? "true" : "false") << endl;
    // Expected: true
    
    vector<int> nums3 = {-1, 3, 2, 0};
    cout << "Example 3 (-1, 3, 2, 0): " << (sol.find132pattern(nums3) ? "true" : "false") << endl;
    // Expected: true
    
    return 0;
}
