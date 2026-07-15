# Isomorphic Strings

**LeetCode #205** · [LeetCode](https://leetcode.com/problems/isomorphic-strings/) · [NeetCode](https://neetcode.io/problems/isomorphic-strings)

- **Difficulty:** Easy
- **Categories:** Hash Table, String
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

## Problem Statement

Given two strings `s` and `t`, determine if they are isomorphic.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Examples:**
```
Input:  s = "egg", t = "add"  →  Output: true
Input:  s = "foo", t = "bar"  →  Output: false
Input:  s = "paper", t = "title"  →  Output: true
```

---

## Intuition

For two strings to be isomorphic, there must be a strict, unique one-to-one (bijective) mapping between characters of `s` and `t` at each position. If a character `s[i]` maps to `t[i]`, then:
1. Every time we see `s[i]`, it must map to `t[i]`.
2. No other character in `s` can map to `t[i]`.

This implies we need to track mappings in both directions: from `s` to `t` and from `t` to `s`. By maintaining two maps, we can guarantee that no mapping conflicts with a previously established mapping and prevent multiple characters from mapping to the same target character.

---

## Approach: Bidirectional Mapping

To solve this:
1. Compare the lengths of `s` and `t`. If they differ, they cannot be isomorphic.
2. Initialize two maps/dictionaries: `mp1` to store mapping from `s` to `t`, and `mp2` to store mapping from `t` to `s`.
3. Iterate through both strings character by character.
4. For each index `i`:
   - If `s[i]` is already in `mp1`, check if it maps to `t[i]`. If not, return `false`.
   - If `t[i]` is already in `mp2`, check if it maps to `s[i]`. If not, return `false`.
   - Otherwise, record the mapping in both maps: `mp1[s[i]] = t[i]` and `mp2[t[i]] = s[i]`.
5. If the loop completes without any conflicts, return `true`.

```cpp
// Check if s and t are isomorphic using bidirectional map tracking
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, char> mp1, mp2;
    
    for (int i = 0; i < s.length(); i++) {
        // If current mappings do not match existing mappings, reject
        if (mp1.count(s[i]) && mp1[s[i]] != t[i]) return false;
        if (mp2.count(t[i]) && mp2[t[i]] != s[i]) return false;
        
        // Establish bidirectional mapping
        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    return true;
}
```

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(N) | We iterate through the strings of length $N$ exactly once. Hash map operations (lookup and insertion) take average $O(1)$ time. |
| **Space** | O(1) | Although we store characters in maps, the size of the mapping is bounded by the size of the character set (at most 256 for standard ASCII characters). |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Empty strings `s = "", t = ""` | `true` |
| Identical strings `s = "abc", t = "abc"` | `true` |
| Different lengths `s = "ab", t = "abc"` | `false` |
| Multiple characters mapping to one `s = "ab", t = "aa"` | `false` |
| One character mapping to multiple `s = "aa", t = "ab"` | `false` |

---

## Files

| File | Description |
|---|---|
| [`bidirectional-map.cpp`](./bidirectional-map.cpp) | Main C++ solution using two hash maps with full inline comments. |
| [`README.md`](./README.md) | Problem description, approach documentation, and complexity analysis. |

---

## Related Problems

- [Word Pattern (LC #290)](https://leetcode.com/problems/word-pattern/) — Same bijection mapping concept, but maps characters in a pattern string to words in a space-separated string.
- [Find and Replace Pattern (LC #890)](https://leetcode.com/problems/find-and-replace-pattern/) — Matching strings in a list to a specific pattern, utilizing the same mapping check.
- [Valid Anagram (LC #242)](https://leetcode.com/problems/valid-anagram/) — Frequency checking of characters, representing a similar string and hash map technique.
