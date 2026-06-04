# Assign Cookies

- **Difficulty:** Easy
- **Categories:** Array, Two Pointers, Greedy, Sorting
- **Time Complexity:** $\mathcal{O}(N \log N + M \log M)$
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(\log N + \log M)$ (for sorting space)

---

## Problem Statement

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child $i$ has a greed factor $g[i]$, which is the minimum size of a cookie that the child will be content with; and each cookie $j$ has a size $s[j]$. If $s[j] \ge g[i]$, we can assign the cookie $j$ to the child $i$, and the child $i$ will be content. Your goal is to maximize the number of your content children and output the maximum number.

---

### Examples

**Example 1:**
- **Input:** `g = [1,2,3]`, `s = [1,1]`
- **Output:** `1`
- **Explanation:** You have 3 children and 2 cookies. The greed factors of the 3 children are 1, 2, 3. 
Even though you have 2 cookies, since their sizes are both 1, you can only make the child whose greed factor is 1 content.
You need to output 1.

**Example 2:**
- **Input:** `g = [1,2]`, `s = [1,2,3]`
- **Output:** `2`
- **Explanation:** You have 2 children and 3 cookies. The greed factors of the 2 children are 1, 2. 
The sizes of the 3 cookies are 1, 2, 3. You can satisfy all children using the cookies of size 1 and 2.

---

### Constraints

- $1 \le g.\text{length}, s.\text{length} \le 3 \cdot 10^4$
- $1 \le g[i], s[j] \le 2^{31} - 1$

---

## Approach: Greedy (Sort + Two Pointers)

The optimal strategy to maximize the number of content children is to be **greedy**:
1. **Satisfy the least greedy child first**: The child with the smallest greed factor is the easiest to satisfy.
2. **Use the smallest possible cookie**: If we can satisfy a child, we should use the smallest cookie that meets their greed requirement. This leaves larger cookies for children with larger greed factors.

### Algorithm Flow

```mermaid
graph TD
    Start([Start]) --> Sort[Sort g and s in ascending order]
    Sort --> Init[Initialize greedIdx = 0, count = 0]
    Init --> Loop{i < s.size()?}
    
    Loop -- Yes --> CheckDone{greedIdx >= g.size()?}
    CheckDone -- Yes --> End([Return count])
    
    CheckDone -- No --> Match{s[i] >= g[greedIdx]?}
    Match -- Yes --> Satisfy[greedIdx++\ncount++]
    Satisfy --> NextCookie[i++]
    Match -- No --> NextCookie
    NextCookie --> Loop
    
    Loop -- No --> End
```

See implementation in [greedy.cpp](file:///Users/abhishekkumar/.gemini/antigravity/scratch/coding/dsa-wiki/assign-cookies/greedy.cpp).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N + M \log M)$
  - Sorting the greed factors array `g` of size $N$ takes $\mathcal{O}(N \log N)$.
  - Sorting the cookie sizes array `s` of size $M$ takes $\mathcal{O}(M \log M)$.
  - The two-pointer traversal takes $\mathcal{O}(N + M)$ in the worst case.
  - Thus, the total time complexity is dominated by sorting, which is $\mathcal{O}(N \log N + M \log M)$.

- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(\log N + \log M)$
  - If we sort the arrays in place, the auxiliary space is $\mathcal{O}(1)$.
  - Depending on the sorting algorithm implementation (e.g., `std::sort`), it may require stack space up to $\mathcal{O}(\log N + \log M)$.

---

## Learn More

- [LeetCode #455 - Assign Cookies](https://leetcode.com/problems/assign-cookies/)
- [NeetCode - Assign Cookies](https://neetcode.io/problems/assign-cookies)
