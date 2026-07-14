# C++ Container Reference Notes

A collection of important syntax reminders, standard library container APIs, and template declarations to keep in mind when solving DSA problems in C++.

---

## 1. Container Element Fetching Methods

Different STL containers use distinct method names to access elements. Using the wrong function name will result in compilation errors.

| Container | Fetch Method | Notes |
| :--- | :--- | :--- |
| `std::priority_queue` | `pq.top()` | Returns a reference to the top (priority-ordered) element. |
| `std::stack` | `s.top()` | LIFO (Last In First Out) — returns a reference to the element at the top. |
| `std::queue` | `q.front()` | FIFO (First In First Out) — returns a reference to the element at the front. |
| `std::vector` / `std::deque` | `v.front()` / `v.back()` | Direct access to both ends of the container. |

> [!TIP]
> **Simple Rule to Remember**:
> - Use `.top()` for `priority_queue` and `stack` (since you examine the "top" of a stack/heap).
> - Use `.front()` for `queue` (since you examine the "front" of a line/queue).

---

## 2. C++ `std::priority_queue` Template Parameters

When declaring a custom priority queue (such as a min-heap or with custom comparators), you must specify all three template parameters:

```cpp
std::priority_queue<Type, Container, Comparator>
```

| Parameter | Purpose | Correct Declaration | Common Mistakes |
| :--- | :--- | :--- | :--- |
| **Type** | The data type stored in the queue. | `std::pair<int, std::string>` | Mismatched pair types |
| **Container** | The underlying container class used to store elements. | `std::vector<std::pair<int, std::string>>` | Omitting or using `vector` without the pair arguments |
| **Comparator** | The comparison struct or std comparator template. | `std::greater<std::pair<int, std::string>>` | Using `greater()` (a function call) instead of a class type |

### Example declarations:

#### Min-Heap of Integers
```cpp
#include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

#### Heap with Custom Pair Comparator (Ascending Frequency, Descending Alphabetical Tiebreaker)
```cpp
#include <queue>
#include <vector>
#include <string>

struct Compare {
    bool operator() (const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
        if (a.first != b.first) return a.first > b.first; // Min-heap on frequency
        return a.second < b.second;                       // Max-heap on string (tiebreaker)
    }
};

std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, Compare> pq;
```
