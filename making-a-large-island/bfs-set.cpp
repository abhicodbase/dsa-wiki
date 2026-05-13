#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * Phase 1 — BFS Island Labeler
   *
   * Performs a BFS from cell (x, y) to explore an entire connected island
   * in the grid. Labels each land cell with a unique `label` ID and returns
   * the total count of land cells (the size) of that island.
   *
   * @param grid    The binary grid input.
   * @param visited A matrix to store the unique label for each land cell.
   * @param label   The unique ID to assign to this specific island.
   * @param x, y    Starting coordinates for the BFS.
   * @return        The total number of cells in the island.
   */
  int getIslandLabelCount(vector<vector<int>> &grid,
                          vector<vector<int>> &visited, int label, int x,
                          int y) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = label;
    int count = 1;

    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        // Skip out-of-bounds cells
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;

        // Only visit land cells that haven't been labeled yet
        if (visited[nx][ny] == 0 && grid[nx][ny] == 1) {
          count++;
          visited[nx][ny] = label;
          q.push({nx, ny});
        }
      }
    }
    return count;
  }

  /**
   * Main Strategy:
   * 1. Pre-calculate Island Sizes: Traverse the grid and label each connected
   *    island with a unique integer ID. Store the size of each labeled island
   *    in a hash map (label -> size).
   * 2. Evaluate Potential Flips: Iterate through every '0' cell. For each '0',
   *    check its 4 neighbors. Collect the unique labels of adjacent islands
   *    (using a set to avoid double-counting the same island).
   * 3. Calculate Max Size: The potential island size if we flip the '0' is:
   *    1 (the flipped cell) + sum of sizes of all unique adjacent islands.
   *
   * Time Complexity : O(N * M) — where N, M are grid dimensions.
   * Space Complexity: O(N * M) — for the `visited` labels and size map.
   */
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    unordered_map<int, int> mp; // label -> size of island
    int label = 1;
    int mx = 0;

    // --- Phase 1: Identify all islands and their sizes ---
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j] == 0 && grid[i][j] == 1) {
          mp[label] = getIslandLabelCount(grid, visited, label, i, j);
          mx = max(mx, mp[label]);
          label++;
        }
      }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int zeroCount = 0;

    // --- Phase 2: Try flipping each '0' to see the resulting island size ---
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          zeroCount++;
          int sum = 0;
          unordered_set<int> s; // Use a set to collect unique neighbor labels

          for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;

            if (visited[nx][ny] != 0) {
              s.insert(visited[nx][ny]);
            }
          }

          // Sum up the sizes of unique adjacent islands
          for (auto islandLabel : s) {
            sum += mp[islandLabel];
          }
          mx = max(mx, sum + 1); // +1 for the flipped '0' cell
        }
      }
    }

    // Edge case: if there are no '0' cells, return the size of the largest island
    if (zeroCount == 0)
      return mx;

    return mx;
  }
};