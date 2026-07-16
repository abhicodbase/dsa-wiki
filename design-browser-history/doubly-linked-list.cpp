/*
 * LeetCode #1472 — Design Browser History
 * https://leetcode.com/problems/design-browser-history/
 *
 * APPROACH: Doubly Linked List
 * ──────────────────────────────────────────────────────────────
 * Model the browser history as a doubly linked list of web pages. Each node contains
 * a URL string and pointers to the previous and next nodes.
 * - visiting a URL: clear all forward history (deallocate memory) and append the new 
 *   node after the current node.
 * - going back: move the current pointer back by at most `steps`.
 * - going forward: move the current pointer forward by at most `steps`.
 *
 * TIME  : visit: O(1) [amortized if deleting forward history, or O(F) where F is the number of forward steps deleted]
 *         back/forward: O(S) where S is the number of steps.
 * SPACE : O(N) — Storing N history nodes.
 */

#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
    struct BrowserNode {
        string url;
        BrowserNode* prev = nullptr;
        BrowserNode* next = nullptr;
    };
    BrowserNode* current;

public:
    /**
     * Initializes the object with the homepage of the browser.
     * 
     * @param homepage The initial home page URL.
     */
    BrowserHistory(string homepage) {
        current = new BrowserNode();
        current->url = homepage;
    }

    /**
     * Destructor to clean up all allocated memory for history nodes.
     */
    ~BrowserHistory() {
        // Go back to the very beginning of history
        while (current->prev) {
            current = current->prev;
        }
        // Delete all nodes forward
        while (current) {
            BrowserNode* temp = current->next;
            delete current;
            current = temp;
        }
    }

    /**
     * Visits a new URL. Clears any forward history.
     * 
     * @param url The URL to visit.
     */
    void visit(string url) {
        // Delete all forward history to prevent memory leaks (orphan nodes)
        BrowserNode* fwd = current->next;
        while (fwd) {
            BrowserNode* temp = fwd->next;
            delete fwd;
            fwd = temp;
        }

        // Create the new node and link it bidirectional
        BrowserNode* node = new BrowserNode();
        node->url = url;
        node->prev = current;
        current->next = node;
        
        // Move current pointer to the new page
        current = node;
    }

    /**
     * Navigates back by at most `steps` in history.
     * 
     * @param steps The maximum number of steps to go back.
     * @return The URL after navigating back.
     */
    string back(int steps) {
        while (steps-- && current->prev) {
            current = current->prev;
        }
        return current->url;
    }

    /**
     * Navigates forward by at most `steps` in history.
     * 
     * @param steps The maximum number of steps to go forward.
     * @return The URL after navigating forward.
     */
    string forward(int steps) {
        while (steps-- && current->next) {
            current = current->next;
        }
        return current->url;
    }
};

int main() {
    // Test Case from LeetCode
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");       // Visit google.com
    browserHistory->visit("facebook.com");     // Visit facebook.com
    browserHistory->visit("youtube.com");      // Visit youtube.com
    
    cout << "Back 1: " << browserHistory->back(1) << " (Expected: facebook.com)" << endl;
    cout << "Back 1: " << browserHistory->back(1) << " (Expected: google.com)" << endl;
    cout << "Forward 1: " << browserHistory->forward(1) << " (Expected: facebook.com)" << endl;
    
    browserHistory->visit("linkedin.com");     // Visit linkedin.com (should delete forward youtube.com)
    
    cout << "Forward 2: " << browserHistory->forward(2) << " (Expected: linkedin.com)" << endl;
    cout << "Back 2: " << browserHistory->back(2) << " (Expected: google.com)" << endl;
    cout << "Back 7: " << browserHistory->back(7) << " (Expected: leetcode.com)" << endl;

    delete browserHistory;
    return 0;
}

/*
 * ALTERNATIVE: Dynamic Array / Vector with Current Index
 * ──────────────────────────────────────────────────────
 * Instead of a doubly linked list, we can store URLs in a dynamic array (std::vector).
 * We maintain a 'current' pointer (an integer index) and a 'max_boundary' pointer.
 * - visit: insert URL at current + 1, truncate everything beyond it, and advance index.
 * - back/forward: update index within bounds [0, max_boundary] in O(1) time.
 *
 *   class BrowserHistory {
 *       vector<string> history;
 *       int curr = 0;
 *       int max_len = 0;
 *   public:
 *       BrowserHistory(string homepage) {
 *           history.push_back(homepage);
 *           curr = 0;
 *           max_len = 1;
 *       }
 *       void visit(string url) {
 *           if (curr + 1 < history.size()) {
 *               history[curr + 1] = url;
 *           } else {
 *               history.push_back(url);
 *           }
 *           curr++;
 *           max_len = curr + 1;
 *       }
 *       string back(int steps) {
 *           curr = max(0, curr - steps);
 *           return history[curr];
 *       }
 *       string forward(int steps) {
 *           curr = min(max_len - 1, curr + steps);
 *           return history[curr];
 *       }
 *   };
 *
 * Trade-off vs current approach: The array-based solution is faster for back() and forward() operations,
 * reducing the time complexity to O(1) compared to O(steps) for linked lists. However, visiting a new URL 
 * in the middle of history may require orphaning elements (which vector handles automatically by keeping capacity,
 * but logically truncating) and may involve occasional resizing overhead.
 *
 * MEMORY SAFETY & LEAK ANALYSIS EXTENSION:
 * ────────────────────────────────────────
 * When implementing a custom linked list in C++ (like `doubly-linked-list.cpp`), we must be careful 
 * to clean up the forward history during `visit` calls, and implement a custom destructor to free 
 * all allocated nodes. Failure to do so leads to significant memory leaks. Using `std::vector` or 
 * smart pointers (`std::shared_ptr` / `std::unique_ptr`) mitigates these concerns automatically.
 */
