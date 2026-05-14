#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Minimum Path Sum
 * Description: Given a m x n grid filled with non-negative numbers, find a path from 
 *              top left to bottom right, which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
    /**
     * Finds the minimum path sum using Dynamic Programming.
     * @param grid The input m x n grid of non-negative integers.
     * @return The minimum sum of numbers along a path from top-left to bottom-right.
     */
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        // sum[i][j] will store the minimum path sum to reach cell (i, j)
        vector<vector<int>> sum(n, vector<int>(m, 0));
        
        // Base case: Starting cell
        sum[0][0] = grid[0][0];
        
        // Initialize the first row: Only one way to reach any cell (from the left)
        for (int i = 1; i < m; i++)
            sum[0][i] = grid[0][i] + sum[0][i - 1];
            
        // Initialize the first column: Only one way to reach any cell (from above)
        for (int i = 1; i < n; i++)
            sum[i][0] = grid[i][0] + sum[i - 1][0];
            
        // Fill the rest of the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // Minimum sum to reach current cell is the cell's value + 
                // the minimum of the paths from above or from the left
                sum[i][j] = grid[i][j] + min(sum[i - 1][j], sum[i][j - 1]);
            }
        }
        
        // The answer is the value at the bottom-right corner
        return sum[n - 1][m - 1];
    }
};