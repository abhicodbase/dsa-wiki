# Design Browser History

**LeetCode #1472** · [LeetCode](https://leetcode.com/problems/design-browser-history/) · [NeetCode](https://neetcode.io/problems/design-browser-history)

- **Difficulty:** Medium
- **Categories:** Array, Linked List, Stack, Design, Doubly-Linked List
- **Time Complexity:** O(1) for `visit`, O(S) for `back`/`forward`
- **Space Complexity:** O(N)

---

## Problem Statement

You have a browser with one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:
- `BrowserHistory(string homepage)` Initializes the object with the `homepage` of the browser.
- `void visit(string url)` Visits `url` from the current page. It clears up all the forward history.
- `string back(int steps)` Moves `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current `url` after moving back in history at most `steps`.
- `string forward(int steps)` Moves `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you will forward only `x` steps. Return the current `url` after forwarding in history at most `steps`.

**Examples:**
```
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
```

---

## Intuition

Browser history naturally acts as a sequence of pages where we can move backward and forward. This linear, bidirectional navigation is perfectly modeled by a **Doubly Linked List**. 

Each node in the list represents a visited page, containing its URL, a pointer to the previous page (`prev`), and a pointer to the next page (`next`).
- When we visit a new URL, we must break any existing `forward` pointer, delete all nodes ahead to prevent memory leaks, and append the new page.
- When we go back or forward, we traverse the list pointers `prev` or `next` up to `steps` times, clamping the movement if we reach either end of the list.

---

## Approach: Doubly Linked List

To implement this:
1. Define a struct `BrowserNode` with a string `url` and pointers `prev` and `next`.
2. Keep a pointer `current` pointing to the current page.
3. **`visit(url)`**: Clear any existing forward nodes (to prevent memory leaks), link the new node as `current->next`, set `node->prev = current`, and move `current` to `node`.
4. **`back(steps)`**: Walk backward along the `prev` pointers up to `steps` times, or until `current->prev` becomes null.
5. **`forward(steps)`**: Walk forward along the `next` pointers up to `steps` times, or until `current->next` becomes null.

```cpp
class BrowserHistory {
    struct BrowserNode {
        string url;
        BrowserNode* prev = nullptr;
        BrowserNode* next = nullptr;
    };
    BrowserNode* current;

public:
    BrowserHistory(string homepage) {
        current = new BrowserNode();
        current->url = homepage;
    }

    void visit(string url) {
        // Delete forward history to prevent leaks
        BrowserNode* fwd = current->next;
        while (fwd) {
            BrowserNode* temp = fwd->next;
            delete fwd;
            fwd = temp;
        }

        BrowserNode* node = new BrowserNode();
        node->url = url;
        node->prev = current;
        current->next = node;
        current = node;
    }

    string back(int steps) {
        while (steps-- && current->prev) {
            current = current->prev;
        }
        return current->url;
    }

    string forward(int steps) {
        while (steps-- && current->next) {
            current = current->next;
        }
        return current->url;
    }
};
```

---

## Bug Analysis & Corrections

In the initial implementation, several critical bugs were identified and resolved:

### 1. Visit Doesn't Clear Forward History (Memory Leak)
* **Problem:** When visiting a new URL after going back in history, the old forward pointer chain is overwritten (`current->next = node`). However, the existing nodes in that forward chain are never deallocated, orphaning them and causing memory leaks.
* **Correction:** Iterate forward from `current->next` and `delete` all forward nodes before setting the new `next` pointer.

### 2. `head->prev = head` (Self-loop)
* **Problem:** During initialization, the code set `node->prev = head` where `head` was `node` itself. This creates a self-loop at the homepage node. If we call `back()` past the homepage, the loop would continue traversing indefinitely instead of stopping.
* **Correction:** Initialize the homepage's `prev` pointer to `nullptr`.

### 3. Loop Termination & Off-by-One Risk in `back`/`forward`
* **Problem:** The original boundary checks were complex and had a fallback `prev->url` return statement that could result in undefined behavior (dereferencing a null pointer if the history was completely empty or had self-loops).
* **Correction:** Simplified the logic to:
  ```cpp
  while (steps-- && current->prev) {
      current = current->prev;
  }
  return current->url;
  ```
  This naturally clamps at the boundary without risks of null pointer dereferencing or boundary errors.

---

## Complexity

| Operation | Time Complexity | Space Complexity | Reason |
|---|---|---|---|
| **Constructor** | O(1) | O(1) | Initializes a single homepage node. |
| **`visit`** | O(F) | O(1) auxiliary | $F$ is the number of forward steps deleted. Inserting the new node itself is $O(1)$. |
| **`back`** | O(S) | O(1) | $S$ is the number of steps traversed back (at most length of history). |
| **`forward`** | O(S) | O(1) | $S$ is the number of steps traversed forward (at most length of forward history). |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Going back more steps than available | Clamps and returns the homepage URL. |
| Going forward more steps than available | Clamps and returns the most recently visited URL. |
| Visiting new URL from homepage | Clears all forward history (none in this case) and establishes a new path. |
| Visiting new URL from middle of history | Safely deletes the old forward nodes and paths, updating the head of the forward chain. |

---

## Files

| File | Description |
|---|---|
| [`doubly-linked-list.cpp`](./doubly-linked-list.cpp) | Main C++ solution using a doubly linked list with full inline comments and memory leak cleanups. |
| [`README.md`](./README.md) | Problem description, approach documentation, bug analysis, and complexity analysis. |

---

## Related Problems

- [LRU Cache (LC #146)](https://leetcode.com/problems/lru-cache/) — Uses a hash map and a doubly linked list to design a custom cache replacement policy.
- [LFU Cache (LC #460)](https://leetcode.com/problems/lfu-cache/) — Complex data structure design requiring multiple doubly linked lists and hash maps.
- [Design Hit Counter (LC #362)](https://leetcode.com/problems/design-hit-counter/) — System design and data structure problem, often solved using queues or circular arrays.
