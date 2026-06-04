#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Finds the maximum number of children that can be satisfied with the given cookies.
     * 
     * @param g The greed factors of the children.
     * @param s The sizes of the cookies.
     * @return The maximum number of children that can be content.
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookiesSize = s.size();
        int childSize = g.size();
        
        // Sort both the greed factors and cookie sizes in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int greedIdx = 0, count = 0;
        
        // Iterate through each cookie
        for (int i = 0; i < cookiesSize; i++) {
            // If all children have been satisfied, we can stop early
            if (greedIdx >= childSize) {
                return count;
            }
            
            // If the current cookie is too small for the current child's greed factor,
            // try the next cookie size
            if (s[i] < g[greedIdx]) {
                continue;
            }
            
            // Otherwise, satisfy the child, move to the next child, and increment the count
            greedIdx++;
            count++;
        }
        
        return count;
    }
};
