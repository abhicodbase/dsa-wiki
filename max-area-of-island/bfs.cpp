#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Problem: Max Area of Island
 * Description: Find the maximum area of an island in a 2D binary grid.
 *              An island is a group of 1's connected 4-directionally.
 */

class Solution {
public:
    /**
     * Helper function to calculate the size of an island using Breadth-First Search (BFS).
     * @param grid The input binary grid.
     * @param visited A 2D boolean vector to track visited cells.
     * @param x The starting row index.
     * @param y The starting column index.
     * @return The size (area) of the island.
     */
    int getIslandSize(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        // Start BFS from the given cell
        q.push({x, y});
        int count = 1;
        visited[x][y] = true;
        
        // Directions for 4-directional connectivity (Right, Down, Left, Up)
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                
                // Boundary check and condition check (land and not visited)
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                    count++;
                    visited[nx][ny] = true; // Mark as visited immediately to avoid redundant processing
                    q.push({nx, ny});
                }
            }
        }
        return count;
    }

    /**
     * Main function to find the maximum area among all islands in the grid.
     * @param grid The input binary grid.
     * @return The maximum area of an island.
     */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        // Keep track of visited cells to ensure each island is counted only once
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int mx = 0;
        
        // Iterate through every cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If we find an unvisited land cell, it's a new island
                if (grid[i][j] == 1 && !visited[i][j]) {
                    // Calculate its size using BFS and update the maximum
                    int islandSize = getIslandSize(grid, visited, i, j);
                    mx = max(mx, islandSize);
                }
            }
        }
        return mx;
    }
};
