#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1)
      return l2;
    if (!l2)
      return l1;
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }

  ListNode *merge(vector<ListNode *> &lists, int left, int right) {
    if (left == right)
      return lists[left];
    int mid = left + (right - left) / 2;
    ListNode *l1 = merge(lists, left, mid);
    ListNode *l2 = merge(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;
    return merge(lists, 0, lists.size() - 1);
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
  cout << "Merged List (Divide & Conquer): ";
  printList(result);

  return 0;
}
