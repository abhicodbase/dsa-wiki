#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Standard BFS implementation for "Number of Islands".
 *
 * Concept:
 * - We iterate through the entire grid.
 * - Every time we find unvisited land ('1'), it marks the START of a new
 * island.
 * - We increment our island count and then trigger a BFS (Breadth-First
 * Search).
 * - The BFS explores EVERY connected land tile of that specific island and
 * marks them as 'visited'.
 * - This ensures that each island is only counted once.
 *
 * Complexity:
 * - Time: O(N * M) - Each cell is visited at most once.
 * - Space: O(min(N, M)) - The BFS queue stores at most the width/height of the
 * island frontier.
 */
int numIslands(vector<vector<char>> &grid) {
  if (grid.empty())
    return 0;

  int rows = grid.size();
  int columns = grid[0].size();

  // Directions for exploring neighbors: Up, Right, Down, Left
  int directionX[4] = {-1, 0, 1, 0};
  int directionY[4] = {0, 1, 0, -1};

  // Keeps track of cells we've already "processed" as part of an island
  vector<vector<bool>> visited(rows, vector<bool>(columns, false));
  int islandCount = 0;

  // 1. Traverse the entire grid cell by cell
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {

      // 2. Found an unvisited piece of land? This is a NEW island.
      if (grid[i][j] == '1' && !visited[i][j]) {
        islandCount++;

        // 3. Start BFS to "sink" or mark the entire island
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true; // Mark the start point as visited

        while (!q.empty()) {
          pair<int, int> current = q.front();
          q.pop();
          int currX = current.first;
          int currY = current.second;

          // 4. Look in all 4 cardinal directions for connected land
          for (int k = 0; k < 4; k++) {
            int nextX = currX + directionX[k];
            int nextY = currY + directionY[k];

            // Boundary checks + Land check + Visit check
            if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < columns &&
                grid[nextX][nextY] == '1' && !visited[nextX][nextY]) {

              visited[nextX][nextY] =
                  true; // Mark as part of the current island
              q.push({nextX,
                      nextY}); // Add to queue to explore its neighbors later
            }
          }
        }
      }
    }
  }

  return islandCount;
}

int main() {
  // Example 1: Single large island
  vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
  cout << "Grid 1 | Output: " << numIslands(grid1) << " (Expected: 1)" << endl;

  // Example 2: Three distinct islands
  vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};
  cout << "Grid 2 | Output: " << numIslands(grid2) << " (Expected: 3)" << endl;

  return 0;
}
