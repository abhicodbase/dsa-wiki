#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Standard BFS implementation for Number of Islands.
 * Time Complexity: O(N * M)
 * Space Complexity: O(min(N, M)) for the queue boundary
 */
int numIslands(vector<vector<char>> &grid) {
  if (grid.empty())
    return 0;
  int rows = grid.size();
  int columns = grid[0].size();
  int directionX[4] = {-1, 0, 1, 0};
  int directionY[4] = {0, 1, 0, -1};
  vector<vector<bool>> visited(rows, vector<bool>(columns, false));
  int count = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      // Find an unvisited piece of land ('1')
      if (grid[i][j] == '1' && !visited[i][j]) {
        // Each new BFS start equals a new island found
        count++;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
          pair<int, int> current = q.front();
          q.pop();
          int idxX = current.first, idxY = current.second;

          // Explore neighbors
          for (int k = 0; k < 4; k++) {
            int x = idxX + directionX[k], y = idxY + directionY[k];
            // Check boundaries and if it's land + unvisited
            if (x >= 0 && x < rows && y >= 0 && y < columns &&
                grid[x][y] == '1' && !visited[x][y]) {
              visited[x][y] = true;
              q.push({x, y});
            }
          }
        }
      }
    }
  }

  return count;
}

int main() {
  vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
  cout << "Grid 1 | Output: " << numIslands(grid1) << endl;

  vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};
  cout << "Grid 2 | Output: " << numIslands(grid2) << endl;

  return 0;
}
