#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int> left, vector<int> right) {
        int i = 0, j = 0;
        vector<int> result;
        
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result.push_back(left[i]);
                i++;
            } else {
                result.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size()) {
            result.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            result.push_back(right[j]);
            j++;
        }
        return result;
    }

    vector<int> mergeSort(vector<int>& nums) {
        int mid = nums.size() / 2;
        if (mid == 0) return nums;
        
        // Creating sub-vectors for left and right halves
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
};
