# Reverse Words in a String

**LeetCode #151** · [LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/) · [NeetCode](https://neetcode.io/problems/reverse-words-in-a-string)

- **Difficulty:** Medium
- **Categories:** Two Pointers, String, Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

## Problem Statement

Given an input string `s`, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.

Note that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

**Examples:**
```
Input:  s = "the sky is blue"       →  Output: "blue is sky the"
Input:  s = "  hello world  "      →  Output: "world hello"
Input:  s = "a good   example"      →  Output: "example good a"
```

---

## Intuition

The goal is to reverse the order of words in a string, while cleaning up any leading, trailing, or duplicate spaces. A stack is a natural fit for this problem because of its Last-In-First-Out (LIFO) property.

By parsing the input string from left to right, we can extract words and push them onto a stack. When we pop them off the stack to rebuild the output, the first word pushed will be the last one popped, effectively reversing the entire sequence of words. Additionally, during extraction, we can easily ignore extra spaces.

---

## Approach: Stack-Based Reversal

To solve this:
1. Initialize a stack `stk` to hold the words and a temporary string `str` to build the current word.
2. Iterate through the characters of string `s`:
   - If we encounter a space and `str` is empty, it means we are scanning leading spaces or duplicate spaces, so we continue.
   - If we encounter a space and `str` is not empty, we have reached a word boundary. We push `str` to the stack and reset `str` to an empty string.
   - Otherwise, append the non-space character to `str`.
3. After the loop, if `str` is not empty, push the last word onto the stack.
4. Construct the output string by popping words from the stack and appending a space between them.

```cpp
string reverseWords(string s) {
    stack<string> stk;
    string str = "";
    
    // Parse characters and push words to stack
    for(int i = 0; i < s.length(); i++) {
        if(str.empty() && s[i] == ' ') continue;
        if(!str.empty() && s[i] == ' ') {
            stk.push(str);
            str = "";
            continue;
        }
        str += s[i];
    }
    if(!str.empty()) stk.push(str);
    
    // Reconstruct the string in reversed order
    string result = "";
    while(!stk.empty()) {
        if(result.empty()) result += stk.top();
        else result += ' ' + stk.top();
        stk.pop();
    }
    return result;
}
```

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(N) | We scan the string of length $N$ once to extract words, and scan the stack once to reconstruct the reversed string. |
| **Space** | O(N) | In the worst case, we store the entire string (divided into words) inside the stack. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Single word `s = "word"` | `"word"` |
| Leading/trailing spaces `s = "  hello world  "` | `"world hello"` |
| Multiple spaces between words `s = "a  b"` | `"b a"` |
| Only spaces `s = "   "` | `""` |

---

## Files

| File | Description |
|---|---|
| [`stack-reversal.cpp`](./stack-reversal.cpp) | Main C++ solution using stack-based reversal with full inline comments. |
| [`README.md`](./README.md) | Problem description, approach documentation, and complexity analysis. |

---

## Related Problems

- [Reverse String (LC #344)](https://leetcode.com/problems/reverse-string/) — Standard character reversal, done in-place.
- [Reverse Words in a String III (LC #557)](https://leetcode.com/problems/reverse-words-in-a-string-iii/) — Reversing each individual word in-place while preserving word order.
- [Simplify Path (LC #71)](https://leetcode.com/problems/simplify-path/) — Splitting folders/paths by slashes and utilizing a stack to resolve relative directories.
