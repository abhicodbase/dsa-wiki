#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * Phase 1 — BFS Island Labeler (Grid 1)
   *
   * Performs a BFS from cell (x, y) and labels every connected land cell
   * in grid1 with the given `island` ID (a unique integer > 0).
   *
   * After this function runs, every cell that belongs to the same island
   * in grid1 carries the same non-zero integer in `visited`.
   *
   * @param grid1   The reference grid that defines what counts as an island.
   * @param visited 2-D map that stores the island-ID for each grid1 land cell.
   * @param x, y    Starting coordinates of the BFS.
   * @param island  Unique island identifier to stamp on all connected cells.
   */
  void visitIsland(vector<vector<int>> &grid1, vector<vector<int>> &visited,
                   int x, int y, int island) {
    int n = grid1.size();
    int m = grid1[0].size();

    // BFS queue holds (row, col) coordinates to explore
    queue<pair<int, int>> q;
    q.push({x, y});

    // Direction vectors for 4-connected neighbours: right, down, left, up
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // Mark the starting cell with the island ID before entering the loop
    visited[x][y] = island;

    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int row = p.first;
      int col = p.second;

      // Explore all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int rx = row + dx[i];
        int ry = col + dy[i];

        // Skip out-of-bounds cells
        if (rx < 0 || rx >= n || ry < 0 || ry >= m) {
          continue;
        }

        // Only enqueue unvisited land cells
        if (visited[rx][ry] == 0 && grid1[rx][ry] == 1) {
          q.push({rx, ry});
          // Label immediately on enqueue to prevent duplicate visits
          visited[rx][ry] = island;
        }
      }
    }
  }

  /**
   * Phase 2 — BFS Sub-Island Validator (Grid 2)
   *
   * Performs a BFS from cell (x, y) over grid2's land cells, checking
   * whether every cell in this connected component carries the SAME island
   * label (`island`) in the `visited` map built from grid1.
   *
   * A grid2 island is a "sub-island" if and only if ALL its cells sit on
   * top of cells that belong to the same single island in grid1.
   *
   * @param grid2       The grid whose islands we want to classify.
   * @param visited     Island-ID map built from grid1 (read-only here).
   * @param gridVisited Tracks which grid2 cells have already been processed.
   * @param x, y        Starting coordinates of the BFS.
   * @param island      Expected grid1 island ID for every cell in this component.
   * @return            true  → this grid2 island is a valid sub-island.
   *                    false → at least one cell falls outside the expected island.
   */
  bool isSubPartVisitIsland(vector<vector<int>> &grid2,
                            vector<vector<int>> &visited,
                            vector<vector<bool>> &gridVisited, int x, int y,
                            int island) {
    int n = grid2.size();
    int m = grid2[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});
    gridVisited[x][y] = true;

    // Direction vectors for 4-connected neighbours: right, down, left, up
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // Assume valid until proven otherwise — we do NOT short-circuit so that
    // the entire island is still marked visited even when invalid.
    bool isValid = true;

    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int row = p.first;
      int col = p.second;

      // Explore all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int rx = row + dx[i];
        int ry = col + dy[i];

        // Skip out-of-bounds cells
        if (rx < 0 || rx >= n || ry < 0 || ry >= m) {
          continue;
        }

        // Only process unvisited grid2 land cells
        if (grid2[rx][ry] == 1 && !gridVisited[rx][ry]) {
          // If this cell belongs to a different (or absent) grid1 island,
          // the current grid2 island cannot be a sub-island
          if (visited[rx][ry] != island) {
            isValid = false;
          }
          q.push({rx, ry});
          // Mark visited immediately on enqueue to prevent re-processing
          gridVisited[rx][ry] = true;
        }
      }
    }
    return isValid;
  }

  /**
   * Main entry point — Count Sub-Islands
   *
   * Strategy (two-phase BFS):
   *   Phase 1 — Label all islands in grid1 with unique integer IDs.
   *   Phase 2 — For every unvisited grid2 island that starts on a labelled
   *              grid1 cell, validate that all its cells share the same ID.
   *              Count only the valid (sub-)islands.
   *
   * Key insight: A grid2 island starting on a water cell of grid1 (visited==0)
   * is rejected immediately before even calling the validator, saving work.
   *
   * Time Complexity : O(M × N)  — each cell is processed at most twice.
   * Space Complexity: O(M × N)  — for the `visited` and `gridVisited` tables.
   *
   * @param grid1 Reference grid defining the "parent" islands.
   * @param grid2 Query grid whose islands we want to classify as sub-islands.
   * @return      Number of sub-islands in grid2.
   */
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int n = grid1.size();
    int m = grid1[0].size();

    // --- Phase 1: Label every island in grid1 with a unique ID ---
    // visited[i][j] == 0 → water (or unvisited land)
    // visited[i][j] == k → land cell belonging to island k
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int currentInitialization = 0; // island ID counter, starts at 1

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // Start a new BFS for every unvisited land cell
        if (grid1[i][j] == 1 && visited[i][j] == 0) {
          currentInitialization++;
          visitIsland(grid1, visited, i, j, currentInitialization);
        }
      }
    }

    // --- Phase 2: Validate each grid2 island against grid1 labels ---
    int count = 0;
    // gridVisited prevents re-processing cells that belong to an already-
    // counted (or already-rejected) grid2 island
    vector<vector<bool>> gridVisited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // Entry conditions:
        //   1. The cell must be land in grid2.
        //   2. The corresponding grid1 cell must belong to some island
        //      (visited[i][j] != 0); otherwise this component cannot be a
        //      sub-island and we skip it entirely.
        //   3. The cell must not have been processed in a previous BFS.
        if (grid2[i][j] == 1 && visited[i][j] != 0 && !gridVisited[i][j]) {
          if (isSubPartVisitIsland(grid2, visited, gridVisited, i, j,
                                   visited[i][j])) {
            count++;
          }
        }
      }
    }
    return count;
  }
};