#include <vector>

using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n - 1;
        
        // 1. Find the peak index in the mountain array
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1; // Peak must be in the right portion
            } else {
                high = mid;    // Peak must be at mid or in the left portion
            }
        }
        int peak = low;

        // 2. Binary search the ascending/inclined portion: [0, peak]
        low = 0;
        high = peak;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // 3. Binary search the descending/declined portion: [peak + 1, n - 1]
        low = peak + 1;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                low = mid + 1;  // In a descending array, larger elements are to the left, smaller to the right
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
