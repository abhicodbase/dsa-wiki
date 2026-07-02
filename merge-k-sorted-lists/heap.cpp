/*
 * Merge K Sorted Lists - Min-Priority Queue (Optimal Heap)
 * Time Complexity: O(N log K)
 * Space Complexity: O(K)
 */
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Custom comparator to order ListNode pointers by their values in ascending order.
    // Since priority_queue in C++ is a max-heap by default, using > yields a min-heap.
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue containing ListNode pointers, capped at size K (one head per list)
        priority_queue <ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push the head of each non-empty linked list into the heap
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        
        ListNode *head = nullptr, *prev = nullptr;
        
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            // Set the head for the final merged list on the first element
            if(head == nullptr) {
                head = node;
            } else {
                // Otherwise link the previous node's next pointer to this node in-place
                prev->next = node;
            }
            prev = node;
            
            // If the popped node has a next element, push it into the heap to keep it sized K
            if(node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return head;
    }
};
