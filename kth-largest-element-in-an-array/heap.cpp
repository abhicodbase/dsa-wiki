#include <queue> // For std::priority_queue and std::greater
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();

    // A min-heap to track the k largest elements seen so far.
    // The top of the min-heap holds the smallest of these k elements.
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
      if (pq.size() < k) {
        // Build the initial heap with the first k elements
        pq.push(nums[i]);
      } else if (nums[i] > pq.top()) {
        // If current element is greater than the smallest element in our
        // k-sized heap, replace the minimum element with the current one. This
        // guarantees the heap retains the k maximum elements.
        pq.pop();
        pq.push(nums[i]);
      }
    }

    // After evaluating all elements, the top of the min-heap is the kth largest
    // element overall.
    return pq.top();
  }
};
