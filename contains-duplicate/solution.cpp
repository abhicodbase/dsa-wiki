#include <vector>
#include <unordered_set>
using namespace std;

/**
 * @brief Determines whether an array contains any duplicate elements.
 *
 * The algorithm uses an `unordered_set` to keep track of values that have been
 * seen while iterating through the array. As soon as a value is found that already
 * exists in the set, we can immediately return `true`. If the loop finishes
 * without finding a duplicate, the array is duplicate‑free.
 *
 * Time Complexity: O(N) – each element is inserted/looked‑up once in the hash set.
 * Space Complexity: O(N) – in the worst case we store all N distinct elements.
 */
class Solution {
public:
    /**
     * @param nums Vector of integers to check.
     * @return true if any value appears more than once, false otherwise.
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int val : nums) {
            // If the value is already in the set, a duplicate exists.
            if (seen.count(val))
                return true;
            seen.insert(val);
        }
        return false; // No duplicates found.
    }
};
