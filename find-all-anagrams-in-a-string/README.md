# Find All Anagrams in a String

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given two strings `s` and `p`, return *an array of all the start indices of `p`'s anagrams in `s`*. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

---

### Examples

**Example 1:**
- **Input:** `s = "cbaebabacd"`, `p = "abc"`
- **Output:** `[0,6]`
- **Explanation:**
  The substring with start index = 0 is "cba", which is an anagram of "abc".
  The substring with start index = 6 is "bac", which is an anagram of "abc".

**Example 2:**
- **Input:** `s = "abab"`, `p = "ab"`
- **Output:** `[0,1,2]`
- **Explanation:**
  The substring with start index = 0 is "ab", which is an anagram of "ab".
  The substring with start index = 1 is "ba", which is an anagram of "ab".
  The substring with start index = 2 is "ab", which is an anagram of "ab".

---

### Constraints
- `1 <= s.length, p.length <= 3 * 10^4`
- `s` and `p` consist of lowercase English letters.

---

## Logic Explanation

The problem asks us to find all anagrams of a string `p` within another string `s`. An anagram is just a string that contains the same characters with the same frequencies. This makes it a perfect candidate for the **Sliding Window** technique combined with a frequency map.

Since the strings only contain lowercase English letters, we can use two arrays of size 26 to act as our frequency maps.

### Sliding Window Approach
1. **Initialization:** First, if `s` is shorter than `p`, it's impossible to find any anagrams, so return an empty array.
2. Initialize two frequency arrays: `anagramP` for the target string `p`, and `anagramS` for the current window in `s`.
3. Populate `anagramP` with the frequencies of characters in `p`. 
4. Initialize the first window of size `p.length()` in `s` by populating `anagramS` with the first `p.length()` characters of `s`.
5. **Sliding the Window:** Start a loop from the end of the initial window (`idx = p.length() - 1`) to the end of `s`.
   - On the first iteration (which represents the initial window), just check if `anagramS == anagramP`. If they match, add the starting index (`idx - len + 1`) to our result.
   - For subsequent iterations, slide the window to the right by one character. 
   - This means removing the effect of the character that falls out of the window on the left (`anagramS[s[idx - len] - 'a']--`) and adding the new character on the right (`anagramS[s[idx] - 'a']++`).
   - Again, compare the two frequency arrays. If they are identical, add the new starting index to the result.
6. Return the accumulated results.

### Complexity
- **Time Complexity:** $O(N)$ where $N$ is the length of string `s`. We iterate through the string once. Comparing the frequency arrays of size 26 takes $O(1)$ time.
- **Space Complexity:** $O(1)$. The auxiliary space used is constant, as our frequency arrays always have a size of 26, regardless of the input size.

---

## Learn More
- [LeetCode](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
- [NeetCode](https://neetcode.io/problems/find-all-anagrams-in-a-string)
