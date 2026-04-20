# Minimum Window Substring

Given two strings `s` and `t`, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. Return an empty string if no such window exists.

### Complexity
- **Time Complexity**: O(|s| + |t|)
- **Space Complexity**: O(|t|)

---
### Approach
Use the sliding window technique with two frequency maps. Expand the right pointer to include characters until all of `t` is covered, then contract the left pointer to minimize the window while maintaining coverage. Track the minimum valid window seen during the process.
