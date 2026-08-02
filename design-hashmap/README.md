# Design HashMap

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Linked List, Design, Hash Function

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Direct Addressing (Array)** | $O(1)$ | $O(K)$ where $K = 10^6$ | Flat array allocation covering the entire key domain. Fast and simple for constrained key bounds. |
| **Separate Chaining (Buckets & LinkedList)** | $O(1)$ avg, $O(N / B)$ worst | $O(N + B)$ | Traditional hash table design handling collisions via linked lists and a modulo hash function. |

---

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:
- `MyHashMap()` initializes the object with an empty map.
- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
- `void remove(int key)` removes the mapping for the `key` if this map contains the mapping.

**Constraints:**
- $0 \le \text{key}, \text{value} \le 10^6$
- At most $10^4$ calls will be made to `put`, `get`, and `remove`.

---

## Approach 1: Direct Addressing Array

Given that the maximum key value is $10^6$, we can allocate a fixed-size vector of size $1,000,001$ pre-filled with `-1`.
- `put(key, val)` $\rightarrow$ `hashMap[key] = val;`
- `get(key)` $\rightarrow$ `return hashMap[key];`
- `remove(key)` $\rightarrow$ `hashMap[key] = -1;`

---

## Approach 2: Separate Chaining (Standard Hash Table)

To handle dynamic or arbitrary key ranges without allocating $10^6$ slots upfront:
1. Use $B = 10007$ buckets (a prime number to reduce hash collision clusters).
2. Compute bucket index using modular arithmetic: `hash(key) = key % B`.
3. Store `pair<int, int>` elements in each bucket's `std::list`.
4. Traverse the bucket's linked list for `put`, `get`, and `remove` operations.

---

## Files

| File | Description |
| :--- | :--- |
| [`vector_direct.cpp`](./vector_direct.cpp) | Direct vector allocation with push_back constructor initialization |
| [`direct_addressing.cpp`](./direct_addressing.cpp) | $O(1)$ direct array lookup with constructor initializer list |
| [`chaining.cpp`](./chaining.cpp) | Separate chaining hash table implementation |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-hashmap)
- [LeetCode](https://leetcode.com/problems/design-hashmap/)
