#include <vector>
using namespace std;

/**
 * @brief Solution class providing methods to find the first and last positions
 * of a target value in a sorted integer array.
 *
 * The implementation uses binary search twice – once to locate the left‑most
 * occurrence ("findFirst") and once to locate the right‑most occurrence
 * ("findLast"). Both searches run in O(log n) time, preserving the overall
 * O(log n) complexity for the combined operation.
 */
class Solution {
public:
  /**
   * @brief Finds the index of the first occurrence of `target` in `nums`.
   *
   * If `target` is not present, returns -1.
   *
   * @param nums   A reference to a sorted vector of integers.
   * @param target The value to locate.
   * @return int  Index of the first occurrence or -1 if absent.
   */
  int findFirst(vector<int> &nums, int target) {
    int low = 0;                // start of search range
    int high = nums.size() - 1; // end of search range
    int result = -1;            // stores the best index found so far

    // Standard binary‑search loop that continues while the range is valid.
    while (low <= high) {
      int mid = (low + high) / 2; // middle index (integer division)
      if (nums[mid] == target) { // target found – record and continue left side
        result = mid;
        high = mid - 1; // shrink range to left half to find earlier index
      } else if (nums[mid] > target) {
        high = mid - 1; // target must be in left half
      } else {
        low = mid + 1; // target must be in right half
      }
    }
    return result; // -1 if never updated
  }

  /**
   * @brief Finds the index of the last occurrence of `target` in `nums`.
   *
   * If `target` is not present, returns -1.
   *
   * @param nums   A reference to a sorted vector of integers.
   * @param target The value to locate.
   * @return int  Index of the last occurrence or -1 if absent.
   */
  int findLast(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int result = -1;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        result = mid;  // record current match
        low = mid + 1; // continue searching to the right for a later index
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return result;
  }

  /**
   * @brief Returns a vector containing the first and last positions of
   * `target`.
   *
   * Utilises `findFirst` and `findLast`. If the target does not exist, both
   * entries will be -1.
   *
   * @param nums   Sorted input array.
   * @param target Value to search for.
   * @return vector<int> of size 2 – [firstIndex, lastIndex].
   */
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result;
    result.push_back(findFirst(nums, target)); // first occurrence
    result.push_back(findLast(nums, target));  // last occurrence
    return result;
  }
};
