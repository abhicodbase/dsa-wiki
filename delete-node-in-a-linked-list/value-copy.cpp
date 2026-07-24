/*
 * LeetCode #237 — Delete Node in a Linked List
 * https://leetcode.com/problems/delete-node-in-a-linked-list/
 *
 * APPROACH: Value Copying & Pointer Bypass
 * ──────────────────────────────────────────────────────────────
 * Since we are given access ONLY to the target node to be deleted and NOT the head 
 * of the linked list, we cannot modify the previous node's `next` pointer directly.
 * Instead of physically removing `node`, we copy the value from `node->next` into `node`, 
 * and then update `node->next` to point to `node->next->next`. This effectively overwrites 
 * and bypasses `node->next`, achieving the exact same result in O(1) time.
 *
 * TIME  : O(1) — Constant time operations (value copy and pointer updates).
 * SPACE : O(1) — No auxiliary memory used.
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Deletes the given node from a singly linked list.
     * Note: The given node is guaranteed NOT to be the tail node.
     * 
     * @param node Pointer to the node in the linked list to be deleted.
     */
    void deleteNode(ListNode* node) {
        // Store pointer to the next node for memory cleanup
        ListNode* temp = node->next;
        
        // Copy the value of the next node into the current node
        node->val = temp->val;
        
        // Bypass the next node
        node->next = temp->next;
        
        // Delete the orphaned next node to prevent memory leaks
        delete temp;
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

    // Build list: 4 -> 5 -> 1 -> 9
    ListNode* node9 = new ListNode(9);
    ListNode* node1 = new ListNode(1, node9);
    ListNode* node5 = new ListNode(5, node1);
    ListNode* head  = new ListNode(4, node5);

    cout << "Original list: ";
    printList(head);

    // Delete node 5
    sol.deleteNode(node5);

    cout << "After deleting node 5: ";
    printList(head);

    // Memory cleanup
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
 * ALTERNATIVE: Iterative Value Shifting (Shift All Nodes Left)
 * ────────────────────────────────────────────────────────────
 * An alternative approach is to loop through the remainder of the linked list,
 * shifting each node's value one step to the left until reaching the end, then
 * deleting the last node.
 *
 *   void deleteNode(ListNode* node) {
 *       ListNode* curr = node;
 *       ListNode* prev = nullptr;
 *       while (curr->next != nullptr) {
 *           curr->val = curr->next->val;
 *           prev = curr;
 *           curr = curr->next;
 *       }
 *       prev->next = nullptr;
 *       delete curr;
 *   }
 *
 * Trade-off vs current approach:
 * The iterative shift method takes O(N) time where N is the number of remaining nodes in the list.
 * The value-copying pointer-bypass approach runs in optimal O(1) time because only one value swap 
 * and pointer re-link is required.
 *
 * TAIL NODE LIMITATION EXTENSION:
 * ───────────────────────────────
 * This O(1) trick relies strictly on the guarantee that `node` is NOT the tail node (`node->next != nullptr`).
 * If `node` were the tail, `node->next` would be `nullptr`, meaning there would be no next value to copy,
 * and we would be unable to set `prev->next = nullptr` without a pointer to `prev`. Deleting a tail node 
 * without access to `head` or `prev` is impossible in a singly-linked list.
 */
