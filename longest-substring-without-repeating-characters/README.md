# Longest Substring Without Repeating Characters

Given a string `s`, find the length of the longest substring without repeating characters.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(min(n, 26)) — at most 26 unique characters

---
### Approach
Use the sliding window technique with a hash map storing each character's most recent index. Maintain a `left` pointer for the window's start. For each character at `right`, if it was seen before and its last index >= `left`, move `left` to `lastIndex + 1` (shrink the window). Always update the character's index and track the max window size.
