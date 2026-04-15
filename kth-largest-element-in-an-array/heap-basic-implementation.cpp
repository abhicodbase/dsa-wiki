#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
  vector<int> heap;

public:
  // Insert element
  void push(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
  }

  // Remove minimum element
  void pop() {
    if (heap.size() == 0)
      return;

    heap[0] = heap.back(); // move last to root
    heap.pop_back();
    heapifyDown(0);
  }

  // Get minimum
  int top() {
    if (heap.size() == 0)
      return -1;
    return heap[0];
  }

  // Size
  int size() { return heap.size(); }

private:
  // Move up
  void heapifyUp(int i) {
    while (i > 0) {
      int parent = (i - 1) / 2;

      if (heap[parent] > heap[i]) {
        swap(heap[parent], heap[i]);
        i = parent;
      } else
        break;
    }
  }

  // 🔽 Move down
  void heapifyDown(int i) {
    int n = heap.size();

    while (true) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int smallest = i;

      if (left < n && heap[left] < heap[smallest])
        smallest = left;

      if (right < n && heap[right] < heap[smallest])
        smallest = right;

      if (smallest != i) {
        swap(heap[i], heap[smallest]);
        i = smallest;
      } else
        break;
    }
  }
};