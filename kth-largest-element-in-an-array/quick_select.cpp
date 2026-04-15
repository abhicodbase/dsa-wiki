#include <vector>

using namespace std;

class Solution {
public:
  int getkthLargest(vector<int> &nums, int pos, int start, int end) {
    int pivot = nums[end];
    int pivotIndex = start;

    // Partition the array around the pivot
    // Elements less than or equal to the pivot move to the left of 'pivotIndex'
    for (int i = start; i < end; i++) {
      if (nums[i] <= pivot) {
        // Swap current element with the element at pivotIndex
        swap(nums[pivotIndex], nums[i]);
        pivotIndex++;
      }
    }

    // Move the pivot to its final sorted position
    swap(nums[pivotIndex], nums[end]);
    // Check if the current pivotIndex is our target position
    if (pivotIndex == pos) {
      return pivot;
    } else if (pivotIndex < pos) {
      // Target is in the right sub-array
      return getkthLargest(nums, pos, pivotIndex + 1, end);
    } else {
      // Target is in the left sub-array
      return getkthLargest(nums, pos, start, pivotIndex - 1);
    }
  }

  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    // The kth largest element is at index (n - k) in a sorted array
    return getkthLargest(nums, n - k, 0, n - 1);
  }
};