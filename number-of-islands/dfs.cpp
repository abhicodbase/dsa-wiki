#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void dfs(vector<vector<char>> &grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0')
      return;

    grid[r][c] = '0';
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int nr = grid.size();
    if (!nr)
      return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }
    return num_islands;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
  cout << "Grid 1 | Output: " << sol.numIslands(grid1) << endl;

  vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};
  cout << "Grid 2 | Output: " << sol.numIslands(grid2) << endl;

  return 0;
}
