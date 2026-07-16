/*
 * LeetCode #83 — Remove Duplicates from Sorted List
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * APPROACH: Single Pass Traversal
 * ──────────────────────────────────────────────────────────────
 * Traverse the sorted linked list using a single pointer. Since the list is sorted, 
 * duplicate values are guaranteed to be adjacent. At each node, check if the current 
 * node's value is equal to the next node's value. If it is, bypass and delete the 
 * next node to avoid memory leaks. Otherwise, advance the pointer to the next node.
 *
 * TIME  : O(N) — We traverse the list of N nodes exactly once.
 * SPACE : O(1) — Only a single pointer is used to traverse the list, modifying it in-place.
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Removes duplicate elements from a sorted linked list.
     * 
     * @param head Pointer to the head of the sorted linked list.
     * @return Pointer to the head of the deduplicated linked list.
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        
        // Traverse the list until the end or the second-to-last node
        while (current && current->next) {
            // If current node's value matches the next node's value
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                // Bypass the duplicate node
                current->next = current->next->next;
                // Free memory to prevent memory leaks in C++
                delete temp; 
            } else {
                // Advance the current pointer if no duplicate is found
                current = current->next;
            }
        }
        
        return head;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: 1 -> 1 -> 2
    ListNode* head1 = new ListNode(1, new ListNode(1, new ListNode(2)));
    cout << "Original List 1: ";
    printList(head1);
    
    ListNode* result1 = sol.deleteDuplicates(head1);
    cout << "Result 1:         ";
    printList(result1);
    
    // Clean up memory
    while (result1) {
        ListNode* temp = result1;
        result1 = result1->next;
        delete temp;
    }

    // Test Case 2: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head2 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    cout << "Original List 2: ";
    printList(head2);
    
    ListNode* result2 = sol.deleteDuplicates(head2);
    cout << "Result 2:         ";
    printList(result2);

    // Clean up memory
    while (result2) {
        ListNode* temp = result2;
        result2 = result2->next;
        delete temp;
    }

    return 0;
}

/*
 * ALTERNATIVE: Recursive Traversal
 * ────────────────────────────────
 * Solve the problem recursively. For each node, recursively process the rest of the list.
 * If the current node has the same value as the head of the processed sublist, bypass it.
 *
 *   ListNode* deleteDuplicates(ListNode* head) {
 *       if (!head || !head->next) return head;
 *       head->next = deleteDuplicates(head->next);
 *       return (head->val == head->next->val) ? head->next : head;
 *   }
 *
 * Trade-off vs current approach: The recursive approach uses O(N) auxiliary space on the call stack 
 * due to recursion, whereas the iterative approach uses O(1) space.
 *
 * UNSORTED LINKED LIST EXTENSION:
 * ───────────────────────────────
 * If the input list were not sorted, duplicates would not necessarily be adjacent. 
 * To handle unsorted lists, we would either need to:
 * 1. Sort the list first (O(N log N) time, O(1) space if using Merge Sort on lists).
 * 2. Keep track of seen values using a hash set (O(N) time complexity, but O(N) auxiliary space).
 */
