#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end) {
        if (start >= end) return;

        int pivot = nums[end];   // Pivot chosen at the end (Lomuto partition)
        int left = start;        // Boundary of elements < pivot

        for (int i = start; i < end; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[left]);
                left++;
            }
        }
        swap(nums[left], nums[end]);  // Place pivot in its correct position

        quickSort(nums, start, left - 1);
        quickSort(nums, left + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
