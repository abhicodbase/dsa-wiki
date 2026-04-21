#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Multi-Source BFS implementation for "01 Matrix".
 *
 * Concept:
 * - Instead of computing distance from each 1-cell individually (O(N²M²)),
 *   we seed the BFS queue with ALL 0-cells simultaneously at distance 0.
 * - BFS naturally fans outward level by level, so the first time any 1-cell
 *   is reached it is guaranteed to be at its minimum distance from a 0-cell.
 * - We use the dist array itself (initialised to -1) as the visited marker.
 *
 * Complexity:
 * - Time:  O(N * M) — every cell is enqueued and processed exactly once.
 * - Space: O(N * M) — for the dist array and the BFS queue.
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // 4-directional movement: right, up, left, down
        int dx[4] = {0, -1, 0,  1};
        int dy[4] = {1,  0, -1, 0};

        // dist[i][j] = -1 means "not yet visited"
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // 1. Seed: enqueue every 0-cell with distance 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // 2. BFS expands outward from all 0-cells simultaneously
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = p.first  + dx[i];
                int ny = p.second + dy[i];

                // Skip: out of bounds or already visited
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1) {
                    continue;
                }

                // First time reaching (nx, ny) → shortest distance from a 0
                dist[nx][ny] = dist[p.first][p.second] + 1;
                q.push({nx, ny});
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> mat1 = {{0, 0, 0},
                                {0, 1, 0},
                                {0, 0, 0}};
    auto res1 = sol.updateMatrix(mat1);
    cout << "Example 1:" << endl;
    for (auto& row : res1) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    // Expected: [[0,0,0],[0,1,0],[0,0,0]]

    // Example 2
    vector<vector<int>> mat2 = {{0, 0, 0},
                                {0, 1, 0},
                                {1, 1, 1}};
    auto res2 = sol.updateMatrix(mat2);
    cout << "\nExample 2:" << endl;
    for (auto& row : res2) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    // Expected: [[0,0,0],[0,1,0],[1,2,1]]

    return 0;
}
