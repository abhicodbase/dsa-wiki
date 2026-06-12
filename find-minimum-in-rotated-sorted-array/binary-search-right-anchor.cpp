/*
 * LeetCode #153 — Find Minimum in Rotated Sorted Array
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * APPROACH: Binary Search — Right Anchor Comparison
 * ──────────────────────────────────────────────────────────────────
 * A sorted array rotated k times still has a single "break point"
 * where the sequence wraps around (e.g. [4,5,6,7,0,1,2]).
 * The minimum always sits at that break point (or at index 0 if the
 * array was not rotated at all).
 *
 * Key insight: compare nums[mid] against nums[h] (the right anchor).
 *   • If nums[mid] > nums[h]  → the break point is to the RIGHT of mid,
 *     so the minimum is strictly in [mid+1 … h].
 *   • Otherwise              → mid itself could be the minimum, so
 *     keep it in contention by moving h = mid (not mid-1).
 * When l == h the two pointers converge on the minimum.
 *
 * TIME  : O(log n) — search space halved every iteration
 * SPACE : O(1)     — only two index variables, no auxiliary storage
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // l and h are inclusive bounds of the current search window
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            // Safe midpoint: avoids integer overflow vs. (l + h) / 2
            // when l + h could exceed INT_MAX for very large arrays
            int mid = l + (h - l) / 2;

            // If the mid value is greater than the rightmost value,
            // the rotation break point (and the minimum) must lie
            // strictly to the right of mid → discard the left half
            if (nums[mid] > nums[h]) {
                l = mid + 1;
            }
            // Otherwise nums[mid] <= nums[h]: the right portion is
            // already sorted, so the minimum is at mid or to its left.
            // Keep mid in the window by setting h = mid (not mid - 1)
            // to avoid accidentally skipping the minimum itself.
            else {
                h = mid;
            }
        }

        // l == h: both pointers have converged on the minimum element
        return nums[l];
    }
};

/*
 * ALTERNATIVE: Linear Scan
 * ─────────────────────────
 * Traverse the array once, tracking the running minimum.
 *
 *   int findMin(vector<int>& nums) {
 *       int mn = nums[0];
 *       for (int x : nums) mn = min(mn, x);
 *       return mn;
 *   }
 *
 * Trade-off: O(n) time vs O(log n) here — acceptable only when the
 * array is tiny or when the constraint of "sorted + rotated" cannot
 * be guaranteed (e.g. the array could contain arbitrary values).
 *
 * EXTENSION — Duplicates (LC #154):
 * When the array may contain duplicate values, nums[mid] == nums[h]
 * is ambiguous (the minimum could be on either side). The fix is:
 *
 *   if (nums[mid] > nums[h])       l = mid + 1;
 *   else if (nums[mid] < nums[h])  h = mid;
 *   else                           h--;   // shrink right bound by 1
 *
 * Worst-case degrades to O(n) (e.g. all equal elements), but average
 * case remains O(log n).
 */
