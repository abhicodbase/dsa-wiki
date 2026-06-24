# Find Duplicate Subtrees

**LeetCode #652** · [LeetCode](https://leetcode.com/problems/find-duplicate-subtrees/) · [NeetCode](https://neetcode.io/problems/find-duplicate-subtrees)

- **Difficulty:** Medium
- **Categories:** Hash Table, Tree, Depth-First Search, Binary Tree
- **Time Complexity:** `O(N^2)` in the worst case (due to string creation and copying of tree serializations), or `O(N)` average for balanced trees.
- **Space Complexity:** `O(N^2)` worst case to store all serialization strings in the hash map.

---

## Problem Statement

Given the root of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are duplicate if they have the **same structure** with the **same node values**.

---

## Intuition

To check if two subtrees are duplicate, we need a way to represent the structure and content of any subtree uniquely. A standard method is **serialization** — converting the subtree layout and values into a single unique string.

Using a post-order traversal (Left → Right → Root):
1. We recursively serialize the left subtree.
2. We recursively serialize the right subtree.
3. We combine them with the current root's value: `(leftStr, val, rightStr)`.

We use parentheses `()` and commas `,` to demarcate subtrees clearly. For example, without strict delimiters:
- A tree with root `1` and left child `11` would serialize to `11,null,null` (or `11,#,#`).
- A tree with root `11` and left child `1` would serialize to `1,1,#,#`.
Adding explicit parentheses `((#,11,#),1,#)` vs `((#,1,#),11,#)` guarantees unique representation, eliminating any structural ambiguity.

We keep track of the frequency of each serialization in a hash map. If we see a serialization exactly **twice** (frequency transitions from 1 to 2), we add its root to our results. We only record it on the second occurrence to avoid adding the same duplicate root multiple times.

---

## Approach: Post-order Serialization + Hash Map

1. Create a helper function `postOrder(root, mp, v)` that returns the string representation of the subtree.
2. In the helper:
   - Base case: If the root is `nullptr`, return a placeholder string (e.g. `"#"`).
   - Recursively serialize the left and right subtrees: `leftStr = postOrder(root->left)` and `rightStr = postOrder(root->right)`.
   - Form the unique serialized string: `str = "(" + leftStr + "," + to_string(root->val) + "," + rightStr + ")"`.
   - Increment the string's frequency in the hash map `mp`.
   - If the new frequency is exactly `2` (`mp[str] == 1` before increment), push the current `root` into the results vector `v`.
   - Return the serialized string `str`.
3. Return the results vector `v`.

---

## Code

```cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Post-order traversal to serialize each subtree and check for duplicates.
     * 
     * Serialization format: "(left,val,right)"
     * Using brackets and commas guarantees unique representation without ambiguity.
     */
    string postOrder(TreeNode* root, unordered_map<string,int>& mp, vector<TreeNode*>& v) {
        // Base case: represent empty node as '#'
        if (!root) return "#";
        
        // Post-order traversal: process left and right subtrees first
        string leftStr  = postOrder(root->left,  mp, v);
        string rightStr = postOrder(root->right, mp, v);
        
        // Combine left representation, root value, and right representation into a unique string
        string str = "(" + leftStr + "," + to_string(root->val) + "," + rightStr + ")";
        
        // Track the occurrence of this serialization in the map
        // Push the root to the results vector ONLY on the 2nd occurrence (mp[str] == 1 before increment)
        // to avoid duplicate additions of the same subtree shape.
        if (mp[str]++ == 1)
            v.push_back(root);
            
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> v;
        postOrder(root, mp, v);
        return v;
    }
};
```

---

## Complexity

| Complexity | Value | Reason |
| :--- | :--- | :--- |
| **Time** | `O(N^2)` | At each of the `N` nodes, we perform string concatenation. In the worst case (a skewed tree), the serialization string at depth `d` has length `O(d)`, leading to `O(N)` string copy operations of size `O(N)`. For balanced trees, the average time is `O(N log N)`. |
| **Space** | `O(N^2)` | The hash map stores the serialization string for every node. The sum of the lengths of all strings in the map is `O(N^2)` in the worst case (skewed tree). The recursion call stack takes `O(H)` space where `H` is the tree height. |

> [!TIP]
> **Optimization to `O(N)` Time and Space:**
> To achieve linear time and space, we can map each unique subtree serialization to a short integer ID. At each node, we lookup the left subtree ID and right subtree ID. The subtree's unique key then becomes `(leftID, root->val, rightID)`. Since this key is of constant size, we can lookup/insert it in `O(1)` time without copy penalties.

---

## Edge Cases

| Scenario | Behavior |
| :--- | :--- |
| Single node tree | Returns an empty vector since no subtrees can be duplicate. |
| Tree with no duplicates | The hash map will have counts of all subtrees as 1; returns empty vector. |
| Multiple duplicates of same shape (e.g. 3 copies) | Checked by `mp[str]++ == 1`. The root is added only when the count transitions from 1 to 2, preventing triplicate roots. |
| Subtrees with same values but different structures | Disambiguated by post-order serialization structure and `#` placeholders. For example, a left-skewed `2 -> 3` vs right-skewed `2 -> 3` will have serializations `((#,3,#),2,#)` and `(#,2,(#,3,#))` respectively. |

---

## Files

| File | Description |
| :--- | :--- |
| [`postorder-serialization.cpp`](./postorder-serialization.cpp) | C++ solution using recursive post-order serialization and frequency mapping |
| [`find_duplicate_subtrees_stepper.html`](./find_duplicate_subtrees_stepper.html) | Interactive step-by-step tree traversal and map visualization of duplicate subtree identification |

### Interactive Demo (`find_duplicate_subtrees_stepper.html`)

An embeddable, step-by-step visualization demonstrating:
- The **active node** during post-order traversal.
- The **serialization string** formed at each subtree.
- The **hash map state** tracking counts.
- Highlighting **duplicate nodes** in red and adding them to the final output list.

---

## Related Problems

- [LC #297 — Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) — Core serialization concepts
- [LC #572 — Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) — Subtree checking and comparisons
- [LC #100 — Same Tree](https://leetcode.com/problems/same-tree/) — Helper function structural verification
