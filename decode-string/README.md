# Decode String

**LeetCode #394** · [LeetCode](https://leetcode.com/problems/decode-string/) · [NeetCode](https://neetcode.io/problems/decode-string)

- **Difficulty:** Medium
- **Categories:** String, Stack
- **Time Complexity:** O(max\_k × n)
- **Space Complexity:** O(n)

---

## Problem Statement

Given an encoded string, decode it. The encoding rule is `k[encoded_string]` — the `encoded_string` inside brackets is repeated exactly `k` times. You may assume the input is always valid; no extra white spaces, brackets are well-formed.

**Examples:**
```
"3[a]2[bc]"       →  "aaabcbc"
"3[a2[c]]"        →  "accaccacc"
"2[abc]3[cd]ef"   →  "abcabccdcdcdef"
"3[a2[bc]]"       →  "abcbcabcbcabcbc"
```

---

## Intuition

The structure is **nested** — `3[a2[bc]]` has a `2[bc]` inside a `3[...]`. When we hit `]` we need to know:
1. How many times to repeat the inner string
2. What the outer string was *before* we entered `[`

A pair of stacks — one for counts, one for string prefixes — lets us **save and restore** that context cleanly at each nesting level. When we enter `[` we freeze state; when we hit `]` we pop, expand, and merge.

---

## Approach: Two-Stack Simulation

Four cases per character:

| Character | Action |
|-----------|--------|
| **digit** | `num = num * 10 + (ch - '0')` — handles multi-digit counts like `12[a]` |
| **`[`** | Push `num` → `countStack`, push `curr` → `stringStack`; reset both |
| **`]`** | Pop count + prev-string; repeat `curr` count times; `curr = prev + expanded` |
| **letter** | `curr += ch` |

### Trace: `"3[a2[bc]]"`

```
char  num  curr         countStack   stringStack
'3'   3    ""           []           []
'['   0    ""           [3]          [""]
'a'   0    "a"          [3]          [""]
'2'   2    "a"          [3]          [""]
'['   0    ""           [3, 2]       ["", "a"]
'b'   0    "b"          [3, 2]       ["", "a"]
'c'   0    "bc"         [3, 2]       ["", "a"]
']'        "a"+"bcbc"   [3]          [""]
           = "abcbc"
']'        ""+"abcbcabcbcabcbc"
           = "abcbcabcbcabcbc"   ← final answer
```

---

## Code

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int>    countStack;
        stack<string> stringStack;

        string curr = "";
        int    num  = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(curr);
                num  = 0;
                curr = "";
            }
            else if (ch == ']') {
                int    cnt  = countStack.top();  countStack.pop();
                string prev = stringStack.top(); stringStack.pop();

                string expanded = "";
                for (int i = 0; i < cnt; i++)
                    expanded += curr;

                curr = prev + expanded;
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};
```

---

## Complexity

| | Value | Reason |
| :--- | :--- | :--- |
| **Time** | `O(N)` | Where `N` is the length of the decoded output string. Every character is processed and written to the output. |
| **Space** | `O(L + N)` | Stack depth is proportional to the input length `L` (nesting level); `N` space is needed for the output string. |

---

## Edge Cases

| Input | Output | Note |
| :--- | :--- | :--- |
| `abc` | `abc` | No brackets — `curr` accumulates directly |
| `10[a]` | `aaaaaaaaaa` | Multi-digit count handled by `num = num * 10 + digit` |
| `3[a2[b4[c]]]` | `abccccbccccabccccbccccabccccbcccc` | Deeply nested brackets; stacks grow to nesting depth and unwind correctly |
| `2[3[a]]` | `aaaaaa` | Outer count applied to already-expanded inner result |

---

## Files

| File | Description |
|------|-------------|
| [`two-stack-simulation.cpp`](./two-stack-simulation.cpp) | C++ two-stack solution with step-by-step trace in comments |

---

## Related Problems

- [LC #726 — Number of Atoms](https://leetcode.com/problems/number-of-atoms/) — same nested bracket pattern, but with element counts
- [LC #1190 — Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/) — stack-based bracket processing
- [LC #20 — Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) — foundational stack + bracket matching
- [LC #227 — Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) — stack simulation with operators and operands
