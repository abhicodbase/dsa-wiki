# Design HashSet

**LeetCode #705** · [LeetCode](https://leetcode.com/problems/design-hashset/) · [NeetCode](https://neetcode.io/problems/design-hashset)

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Linked List, Design, Hash Function
- **Time Complexity:** O(1)
- **Space Complexity:** O(K) where $K$ is the maximum key bound ($10^6$)

---

## Problem Statement

Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:
- `void add(key)` Inserts the value `key` into the HashSet.
- `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.
- `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.

**Examples:**
```
Input:
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]

Output:
[null, null, null, true, false, null, true, null, false]
```

---

## Intuition

A HashSet stores unique keys and supports insertion, deletion, and membership checking in constant time.

When the domain of keys is bounded by a reasonable integer range (in this problem, $0 \le \text{key} \le 10^6$), we can use a **Direct Address Table** — an array where the key itself serves as the index. The value stored at index `key` is a boolean indicating whether `key` is present in the set.

By pre-allocating an array of size $1,000,001$, `add`, `remove`, and `contains` operations simplify to simple array index reads and writes, achieving guaranteed $O(1)$ time complexity without hash collisions or pointer overhead.

---

## Approach: Direct Address Table (Boolean Array)

To implement this:
1. Allocate a boolean array (or `std::vector<bool>` in C++) of size $1,000,001$, initialized to `false`.
2. **`add(key)`**: Set `hashSet[key] = true`.
3. **`remove(key)`**: Set `hashSet[key] = false`.
4. **`contains(key)`**: Return `hashSet[key]`.

In C++, `std::vector<bool>` is a specialized template that compresses each boolean element to a single bit. A size of $1,000,001$ booleans takes only $\sim 122 \text{ KB}$ of memory.

```cpp
class MyHashSet {
private:
    vector<bool> hashSet;

public:
    // Initialize vector of size 1,000,001 with default value false
    MyHashSet() : hashSet(1000001, false) {}

    // Mark index key as present
    void add(int key) {
        hashSet[key] = true;
    }

    // Mark index key as absent
    void remove(int key) {
        hashSet[key] = false;
    }

    // Direct O(1) membership check
    bool contains(int key) {
        return hashSet[key];
    }
};
```

---

## Complexity

| Operation | Time Complexity | Space Complexity | Reason |
|---|---|---|---|
| **`MyHashSet()`** | O(K) | O(K) | Initializes a boolean vector of size $K = 1,000,001$. |
| **`add(key)`** | O(1) | O(1) auxiliary | Direct array indexing and boolean assignment. |
| **`remove(key)`** | O(1) | O(1) auxiliary | Direct array indexing and boolean assignment. |
| **`contains(key)`** | O(1) | O(1) auxiliary | Direct array indexing and boolean read. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Minimum key boundary `key = 0` | Supported (`hashSet[0]`). |
| Maximum key boundary `key = 1,000,000` | Supported (`hashSet[1000000]`). |
| Duplicate `add(key)` calls | Idempotent; setting `true` repeatedly maintains key presence without duplicates. |
| `remove(key)` on a key not present | Safe no-op; setting `false` on an already `false` index changes nothing. |
| `contains(key)` before adding | Returns `false`. |

---

## Files

| File | Description |
|---|---|
| [`direct-address-table.cpp`](./direct-address-table.cpp) | Main C++ solution using a direct address table (`vector<bool>`) with full inline comments and test cases. |
| [`README.md`](./README.md) | Problem description, approach documentation, complexity analysis, and edge cases. |

---

## Related Problems

- [Design HashMap (LC #706)](https://leetcode.com/problems/design-hashmap/) — Similar design problem requiring key-value mapping instead of set membership.
- [Contains Duplicate (LC #217)](https://leetcode.com/problems/contains-duplicate/) — Practical application of set membership testing to detect array duplicates.
- [Design Skiplist (LC #1206)](https://leetcode.com/problems/design-skiplist/) — Advanced data structure design for probabilistic set and map operations.
