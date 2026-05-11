#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num = prices.size();
        int mx = 0;

        // maxRight[i] stores the maximum price from index i to the end.
        // This lets us quickly know the best sell price for any given buy day.
        vector<int> maxRight(num, 0);

        // Base case: the rightmost element is the max price from that point
        maxRight[num - 1] = prices[num - 1];

        // Fill right-to-left: maxRight[i] = max of prices[i] and everything to its right
        for (int i = num - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], prices[i]);
        }

        // For each day i as the buy day, the best sell is maxRight[i].
        // Profit = maxRight[i] - prices[i]; track the global maximum.
        for (int i = 0; i < num; i++) {
            mx = max(mx, maxRight[i] - prices[i]);
        }

        return mx;
    }
};
