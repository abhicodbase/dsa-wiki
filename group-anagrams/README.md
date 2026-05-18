# Group Anagrams - Explanation

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

---

## Approach 1: Sorting (Categorize by Sorted String)

### The Core Idea

Two strings are anagrams if and only if their sorted strings are equal. Therefore, we can use the sorted version of a string as its canonical representation (key) in a hash map. The value for each key will be a list containing all the original strings that map to that key.

### Algorithm Steps

1. Create a hash map `result` mapping strings (the sorted canonical string) to lists of strings (the anagram groups).
2. Iterate through each string `str` in the input array `strs`.
3. For each string:
   - Create a copy of `str` called `sorted_str`.
   - Sort `sorted_str` in ascending order.
   - Use `sorted_str` as a key in the hash map and append the original `str` to the corresponding list.
4. After processing all strings, iterate through the values of the hash map and collect them into a single list of lists.
5. Return the resulting list of lists.

### Complexity
- **Time Complexity:** O(N * K log K) where N is the length of `strs`, and K is the maximum length of a string in `strs`. The outer loop runs N times. Sorting each string takes O(K log K) time.
- **Space Complexity:** O(N * K) because all strings from `strs` will be stored in the hash map.

---

## Approach 2: Categorize by Character Count (Optimal)

### The Core Idea

Two strings are anagrams if and only if their character counts (frequencies of each letter) are the same. Instead of sorting (which takes O(K log K)), we can build an array or string representation of the character counts (size 26 for lowercase English letters) and use that as the key in our hash map.

### Complexity
- **Time Complexity:** O(N * K) where N is the length of `strs`, and K is the maximum length of a string in `strs`. Counting each string takes O(K) time.
- **Space Complexity:** O(N * K) to store the result and hash map.

---

## Common Pitfalls

### 1. Modifying the original string
**Problem:** Using the original string reference and sorting it modifies the input and ruins the result.  
**Fix:** Always make a copy of the string before sorting it to find the canonical key.

### 2. Using an inappropriate map key type
**Problem:** In C++, `std::vector<int>` is perfectly fine as a key in `std::map`, but not natively supported in `std::unordered_map` without a custom hash function.  
**Fix:** For an optimal frequency-count solution in C++, either use `std::map` (adds O(log M) lookup time where M is unique keys), provide a custom hash function for `std::unordered_map`, or encode the frequency array into a string (e.g., `#2#1#0...`) and use the string as the key for `std::unordered_map`.

---

## Learn More (External Resources)

- [NeetCode - Group Anagrams](https://neetcode.io/problems/group-anagrams)
- [LeetCode Problem #49](https://leetcode.com/problems/group-anagrams/)
