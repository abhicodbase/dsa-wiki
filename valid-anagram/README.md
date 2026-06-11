# Valid Anagram

**LeetCode #242** · [LeetCode](https://leetcode.com/problems/valid-anagram/) · [NeetCode](https://neetcode.io/problems/valid-anagram)

- **Difficulty:** Easy
- **Categories:** Hash Table, String, Sorting
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an **anagram** of `s`, and `false` otherwise.

An anagram is a word formed by rearranging the letters of another, using all original letters exactly once.

**Examples:**
```
Input:  s = "anagram", t = "nagaram"  →  Output: true
Input:  s = "rat",     t = "car"      →  Output: false
```

---

## Intuition

Two strings are anagrams if and only if they contain **exactly the same characters with exactly the same frequencies**. Since the input is constrained to lowercase English letters (`a`–`z`), we can represent frequencies in a fixed-size array of length 26 — no sorting or hash map required.

---

## Approach: Dual Character Frequency Arrays

Maintain two frequency arrays `st[26]` and `tt[26]`, one for each string. After populating both:
- If `st[i] == tt[i]` for every `i` → anagram ✓
- If any `st[i] != tt[i]` → not an anagram ✗

**Key trick:** `s[i] - 'a'` maps a character to its 0-based index:
```
'a' → 0, 'b' → 1, … , 'z' → 25
```

```cpp
// Early exit: different lengths cannot be anagrams
if (s.length() != t.length()) return false;

vector<int> st(26, 0), tt(26, 0);

for (char c : s) st[c - 'a']++;    // build frequency table for s
for (char c : t) tt[c - 'a']++;    // build frequency table for t

for (int i = 0; i < 26; i++)
    if (st[i] != tt[i]) return false;

return true;
```

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time** | O(N) | Three linear passes: over `s`, over `t`, and over the 26-element result |
| **Space** | O(1) | Always exactly 2 × 26 = 52 integers — constant regardless of input length |

> `N` = `max(s.length(), t.length())`

---

## Alternative: Single Frequency Array

Use one array — increment for `s`, decrement for `t`. If all counts end at 0, it's an anagram:

```cpp
vector<int> freq(26, 0);
for (char c : s) freq[c - 'a']++;
for (char c : t) freq[c - 'a']--;
for (int f : freq) if (f != 0) return false;
return true;
```

Same O(N) time and O(1) space, but slightly more compact.

---

## Edge Cases

| Scenario | Result |
|---|---|
| `s.length() != t.length()` | `false` immediately (fast exit) |
| `s == t` (identical strings) | `true` |
| Single character strings, same | `true` |
| Single character strings, different | `false` |
| All same character repeated (`"aaa"`, `"aaa"`) | `true` |

---

## Unicode Extension

The fixed 26-slot array only works for **lowercase English letters**. For Unicode / arbitrary characters, use a hash map instead:

```cpp
unordered_map<char, int> freq;
for (char c : s) freq[c]++;
for (char c : t) freq[c]--;
for (auto& [ch, cnt] : freq)
    if (cnt != 0) return false;
return true;
// Time: O(N), Space: O(k) where k = distinct characters
```

---

## Files

| File | Description |
|---|---|
| [`frequency-array.cpp`](./frequency-array.cpp) | Dual-array C++ solution with full inline comments |

---

## Related Problems

- [Group Anagrams (LC #49)](https://leetcode.com/problems/group-anagrams/) — Group multiple strings by anagram equivalence
- [Find All Anagrams in a String (LC #438)](https://leetcode.com/problems/find-all-anagrams-in-a-string/) — Sliding window anagram detection
- [Minimum Number of Steps to Make Two Strings Anagram (LC #1347)](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/) — Count character swaps needed
- [Ransom Note (LC #383)](https://leetcode.com/problems/ransom-note/) — Same frequency-count pattern
