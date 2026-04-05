#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode {
  bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, CompareNode> pq;

    for (auto list : lists) {
      if (list)
        pq.push(list);
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();

      tail->next = node;
      tail = tail->next;

      if (node->next) {
        pq.push(node->next);
      }
    }

    return dummy.next;
  }
};

void printList(ListNode *node) {
  while (node) {
    cout << node->val << (node->next ? " -> " : "");
    node = node->next;
  }
  cout << endl;
}

int main() {
  Solution sol;
  ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
  ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  ListNode *l3 = new ListNode(2, new ListNode(6));
  vector<ListNode *> lists = {l1, l2, l3};

  ListNode *result = sol.mergeKLists(lists);
  cout << "Merged List: ";
  printList(result);

  return 0;
}
