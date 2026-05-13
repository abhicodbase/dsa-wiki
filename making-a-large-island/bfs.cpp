#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Brute Force Approach:
 * For every cell in the grid that contains a '0', we temporarily treat it as a '1'
 * and calculate the size of the island it belongs to using BFS.
 *
 * Time Complexity : O(N^2 * M^2) — For each '0' (up to N*M), we run a BFS (up to N*M).
 * Space Complexity: O(N * M)     — For the visited matrix in each BFS.
 */
class Solution {
public:
  /**
   * Calculates the total size of the island formed by flipping grid[x][y] to 1.
   *
   * @param grid The original binary grid.
   * @param x, y The coordinates of the '0' cell being flipped.
   * @return     The size of the connected island containing (x, y).
   */
  int getTotalReachNodes(vector<vector<int>> &grid, int x, int y) {
    int n = grid.size();
    int m = grid[0].size();
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int count = 1; // Start with 1 for the flipped cell itself

    // Use a visited matrix for each BFS to avoid cycles and redundant counting
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        // Bounds check
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;

        // If it's an unvisited land cell, include it in the island size
        if (!visited[nx][ny] && grid[nx][ny] == 1) {
          count++;
          q.push({nx, ny});
          visited[nx][ny] = true;
        }
      }
    }
    return count;
  }

  /**
   * Main entry point for the brute-force solution.
   */
  int largestIsland(vector<vector<int>> &grid) {
    int mx = 0;
    int n = grid.size();
    int m = grid[0].size();

    // Iterate through every cell in the grid
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // If we find a '0', calculate the potential island size if we flip it
        if (grid[i][j] == 0) {
          mx = max(mx, getTotalReachNodes(grid, i, j));
        }
      }
    }

    // Edge case: if there were no '0's, the grid is already all '1's.
    if (mx == 0) {
      return n * m;
    }

    return mx;
  }
};