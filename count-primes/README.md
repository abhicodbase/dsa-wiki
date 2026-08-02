# Count Primes

- **Difficulty:** Medium
- **Categories:** Array, Math, Enumeration, Number Theory

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Sieve of Eratosthenes** | $O(N \log \log N)$ | $O(N)$ | Standard sieve algorithm. Marks composite numbers starting from $i^2$. |

---

Given an integer `n`, return the number of prime numbers strictly less than `n`.

**Examples:**
```text
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, which are 2, 3, 5, 7.

Input: n = 0
Output: 0

Input: n = 1
Output: 0
```

---

## Approach: Sieve of Eratosthenes

1. **Boolean Array Setup**:
   - Create a boolean array `isPrime` of size `n` initialized to `true`.
   - Set `isPrime[0] = isPrime[1] = false` since $0$ and $1$ are not prime numbers.

2. **Marking Composites**:
   - Iterate $i$ from $2$ up to $\sqrt{n}$ (i.e. $i \times i < n$).
   - If $i$ is prime (`isPrime[i] == true`), mark all of its multiples starting from $i \times i$ as `false`.
   - **Why start at $i \times i$?** Multiples of $i$ less than $i \times i$ (such as $2i, 3i, \dots, (i-1)i$) have already been marked by smaller prime factors ($2, 3, \dots, i-1$).
   - **Overflow Avoidance**: Use 64-bit integer (`long long`) for $i \times i$ to prevent 32-bit integer overflow when $n$ is large.

3. **Counting Primes**:
   - Count all remaining `true` entries in `isPrime` from $2$ to $n - 1$.

---

## Files

| File | Description |
| :--- | :--- |
| [`sieve.cpp`](./sieve.cpp) | Optimal $O(N \log \log N)$ C++ solution using the Sieve of Eratosthenes |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-primes)
- [LeetCode](https://leetcode.com/problems/count-primes/)
