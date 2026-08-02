#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        
        // Build 1-based prefix sum array
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        
        // Find pivot index where left sum equals right sum
        for (int i = 1; i <= n; i++) {
            int leftSum = sum[i - 1];
            int rightSum = sum[n] - sum[i];
            if (leftSum == rightSum) {
                return i - 1;
            }
        }
        
        return -1;
    }
};
