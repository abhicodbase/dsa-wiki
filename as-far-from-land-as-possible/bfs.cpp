class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          q.push({i, j});
      }
    }
    int count = -1;
    if (q.size() == n * n)
      return count;
    while (!q.empty()) {
      int sze = q.size();
      count++;
      for (int i = 0; i < sze; i++) {
        pair<int, int> p = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) {
          int nx = p.first + dx[j];
          int ny = p.second + dy[j];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
          if (grid[nx][ny] == 0) {
            q.push({nx, ny});
            grid[nx][ny] = -1;
          }
        }
      }
    }
    return count;
  }
};