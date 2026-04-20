# Find Median from Data Stream

Design a data structure that supports adding integers from a data stream and returning the median of all elements seen so far.

### Complexity
- **Time Complexity**: O(log n) for `addNum`, O(1) for `findMedian`
- **Space Complexity**: O(n)

---
### Approach
Use two heaps:
- A **max-heap** (`lo`) for the lower half of numbers.
- A **min-heap** (`hi`) for the upper half of numbers.

Maintain the invariant that `lo.size() == hi.size()` or `lo.size() == hi.size() + 1`. On each insert, balance the heaps so the median is always accessible at the tops. If total count is odd, median = `lo.top()`; if even, median = average of both tops.
