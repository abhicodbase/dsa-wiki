/*
 * LeetCode #852 — Peak Index in a Mountain Array
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/
 *
 * APPROACH: Binary Search on Slope
 * ──────────────────────────────────────────────────────────────
 * A mountain array strictly increases to a single peak element and then strictly 
 * decreases. We can use binary search by evaluating the local slope at `mid`:
 * - If `arr[mid] > arr[mid - 1]` and `arr[mid] > arr[mid + 1]`, `mid` is the peak.
 * - If `arr[mid] < arr[mid + 1]`, we are on the ascending slope, so the peak lies right (`start = mid + 1`).
 * - Otherwise (`arr[mid] > arr[mid + 1]`), we are on the descending slope, so the peak lies left (`end = mid`).
 *
 * TIME  : O(log N) — Halves the search space in each iteration.
 * SPACE : O(1)     — Uses a constant amount of memory for search range pointers.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Finds the index of the peak element in a mountain array.
     * 
     * @param arr The mountain array (length >= 3).
     * @return The peak index.
     */
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        // Binary search loop until search space converges to a single element
        while (start < end) {
            // Prevent integer overflow when calculating midpoint
            int mid = start + (end - start) / 2;

            // Direct check: if mid is strictly greater than both neighbors, it is the peak
            if (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            
            // Ascending slope: peak is to the right
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } 
            // Descending slope: peak is at mid or to the left
            else {
                end = mid;
            }
        }

        // `start` converges to the peak index
        return start;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {0, 1, 0};
    cout << "Peak of [0, 1, 0]: " << sol.peakIndexInMountainArray(arr1) << " (Expected: 1)" << endl;

    vector<int> arr2 = {0, 2, 1, 0};
    cout << "Peak of [0, 2, 1, 0]: " << sol.peakIndexInMountainArray(arr2) << " (Expected: 1)" << endl;

    vector<int> arr3 = {0, 10, 5, 2};
    cout << "Peak of [0, 10, 5, 2]: " << sol.peakIndexInMountainArray(arr3) << " (Expected: 1)" << endl;

    return 0;
}

/*
 * ALTERNATIVE: Linear Scan
 * ────────────────────────
 * Iterate through the array linearly and return the index `i` where `arr[i] > arr[i + 1]`.
 *
 *   int peakIndexInMountainArray(vector<int>& arr) {
 *       int i = 0;
 *       while (arr[i] < arr[i + 1]) {
 *           i++;
 *       }
 *       return i;
 *   }
 *
 * Trade-off vs current approach:
 * Linear scan takes O(N) time in the worst case (e.g., peak near the end of a long array).
 * Binary search takes O(log N) time, making it significantly faster for large arrays ($N \le 10^5$).
 *
 * TERNARY SEARCH EXTENSION:
 * ─────────────────────────
 * Since the array is unimodal (strictly increasing then strictly decreasing), a Ternary Search
 * could also find the peak in O(log3 N) time by splitting the range into three parts using `m1` and `m2`.
 * However, standard binary search is simpler to implement and requires fewer comparisons per step.
 */
