#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
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
          grid[r][c] = '0';
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first;
            int col = rc.second;
            if (row - 1 >= 0 && grid[row - 1][col] == '1') {
              neighbors.push({row - 1, col});
              grid[row - 1][col] = '0';
            }
            if (row + 1 < nr && grid[row + 1][col] == '1') {
              neighbors.push({row + 1, col});
              grid[row + 1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col - 1] == '1') {
              neighbors.push({row, col - 1});
              grid[row][col - 1] = '0';
            }
            if (col + 1 < nc && grid[row][col + 1] == '1') {
              neighbors.push({row, col + 1});
              grid[row][col + 1] = '0';
            }
          }
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
