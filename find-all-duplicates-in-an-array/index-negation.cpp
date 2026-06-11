/*
 * LeetCode #442 — Find All Duplicates in an Array
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/
 *
 * APPROACH: Index as Hash (In-place Negation)
 * ────────────────────────────────────────────
 * The key constraint: every integer is in range [1, n] where n = nums.size().
 * This means every value maps to a valid index: value v → index (v - 1).
 *
 * We treat the sign of nums[v-1] as a "visited" flag for value v:
 *   - First time we see v  → negate nums[v-1]  (mark as visited)
 *   - Second time we see v → nums[v-1] is already negative (already visited)
 *                          → v is a duplicate, collect it
 *
 * This avoids any extra data structure — the array itself is the hash map.
 *
 * TIME  : O(N)  — single pass over all n elements
 * SPACE : O(1)  — no extra space used (output array not counted)
 */

#include <vector>
#include <cstdlib>  // abs()

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;  // collects all duplicate values

        for (int i = 0; i < (int)nums.size(); i++) {
            // Use abs() because nums[i] may have already been negated in a
            // previous iteration (when a different index referenced this slot).
            // abs() recovers the original value regardless of current sign.
            int x = abs(nums[i]);

            // x is the current element's original value.
            // Map x to its "marker index": value x → index (x - 1).
            // Values are in [1, n], so (x - 1) is always a valid index.

            // Flip the sign at the marker index to record "we've seen x"
            nums[x - 1] = -nums[x - 1];

            // After flipping:
            //   nums[x-1] < 0  → this is the FIRST visit to x (just marked)
            //   nums[x-1] > 0  → we flipped it twice → SECOND visit → duplicate!
            //   (flipping a negative gives positive, revealing the second visit)
            if (nums[x - 1] > 0) {
                result.push_back(x);  // x appeared twice → duplicate
            }
        }

        return result;
    }
};

/*
 * TRACE EXAMPLE: nums = [4, 3, 2, 7, 8, 2, 3, 1]
 * ──────────────────────────────────────────────────
 * i=0: x=4  → negate nums[3]=7   → nums[3]=-7   (first visit to 4)
 * i=1: x=3  → negate nums[2]=2   → nums[2]=-2   (first visit to 3)
 * i=2: x=2  → negate nums[1]=3   → nums[1]=-3   (first visit to 2)
 * i=3: x=7  → negate nums[6]=3   → nums[6]=-3   (first visit to 7)
 * i=4: x=8  → negate nums[7]=1   → nums[7]=-1   (first visit to 8)
 * i=5: x=2  → negate nums[1]=-3  → nums[1]=+3 > 0 → DUPLICATE: 2
 * i=6: x=3  → negate nums[2]=-2  → nums[2]=+2 > 0 → DUPLICATE: 3
 * i=7: x=1  → negate nums[0]=4   → nums[0]=-4   (first visit to 1)
 * Result: [2, 3]
 *
 * WHY TWO FLIPS = POSITIVE?
 * ──────────────────────────
 * Start: nums[x-1] = +k  (any positive integer)
 * 1st visit: -k            (negative → "visited")
 * 2nd visit: -(-k) = +k   (positive again → "seen twice" = duplicate)
 * The sign is a 1-bit flag embedded inside the existing array values.
 *
 * ALTERNATIVE: HashSet
 * ─────────────────────
 * Use an unordered_set to track seen values. Simpler but O(N) extra space:
 *
 *   unordered_set<int> seen;
 *   vector<int> result;
 *   for (int num : nums) {
 *       if (!seen.insert(num).second)  // insert returns false if already exists
 *           result.push_back(num);
 *   }
 *   return result;
 *
 * Trade-off: O(N) space vs O(1) space with negation trick.
 * Use HashSet when you cannot mutate the input array.
 */
