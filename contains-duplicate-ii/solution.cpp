#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief Determines if the array contains two equal elements whose indices are
 *        at most `k` apart.
 *
 * The algorithm stores the most recent index of each element in an
 * `unordered_map`. While iterating, if we encounter a value that already exists
 * in the map and the distance between the current index and the stored index is
 * ≤ `k`, we have found a qualifying pair.
 *
 * Time Complexity: O(N) – each element is processed once.
 * Space Complexity: O(N) – in the worst case we store all distinct elements.
 */
class Solution {
public:
    /**
     * @param nums Vector of integers.
     * @param k    Maximum allowed index distance.
     * @return true if such a pair exists, false otherwise.
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIdx; // value -> most recent index
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int val = nums[i];
            auto it = lastIdx.find(val);
            if (it != lastIdx.end() && i - it->second <= k) {
                return true; // found nearby duplicate
            }
            // Update the most recent index for this value
            lastIdx[val] = i;
        }
        return false; // no qualifying pair found
    }
};
