#include <vector>

using namespace std;

class Solution {
private:
    void merge(vector<int>& nums, int start, int mid, int end, vector<int>& temp) {
        int i = start, j = mid + 1, k = start;
        
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= end) temp[k++] = nums[j++];
        
        for (int idx = start; idx <= end; idx++) {
            nums[idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end, vector<int>& temp) {
        if (start >= end) return;
        
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid, temp);
        mergeSort(nums, mid + 1, end, temp);
        merge(nums, start, mid, end, temp);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};
