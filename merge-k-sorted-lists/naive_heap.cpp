/*
 * Merge K Sorted Lists - Naive Heap Approach (Unoptimized)
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Traverse all lists and push every node's value into the priority queue.
        // This causes the priority queue to grow to size N (total nodes).
        for(int i = 0; i < n; i++) {
            ListNode* head = lists[i];
            while (head != nullptr) {
                pq.push(head->val);
                head = head->next;
            }
        }
        
        // Re-construct the merged list by popping elements and allocating new nodes.
        // This duplicates the list nodes in dynamic memory instead of re-linking in-place.
        ListNode *head = nullptr, *prev = nullptr;
        while(!pq.empty()) {
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            if(head == nullptr) {
                head = node;
                prev = node;
            } else {
                prev->next = node;
                prev = node;
            }
        }
        return head;
    }
};
