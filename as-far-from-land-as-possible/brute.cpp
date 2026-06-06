#include <vector>
#include <climits>
using namespace std;

/**
 * @brief Problem: As Far From Land As Possible
 *
 * Given a grid where 0 represents water and 1 represents land, find the
 * maximum distance from any water cell to the nearest land cell. The distance
 * is measured using Manhattan distance.
 *
 * This file contains a **brute‑force** solution that enumerates every water‑land
 * pair, computes the Manhattan distance, keeps the minimum distance for each
 * water cell, and finally returns the maximum of those minima.
 *
 * Time Complexity: O(W * L) where W is the number of water cells and L is the
 * number of land cells (worst‑case O(N^4) for an N×N grid).
 * Space Complexity: O(W + L) for storing the coordinates of water and land cells.
 */
class Solution {
public:
    /**
     * @brief Computes the maximum distance from any water cell to the nearest land.
     * @param grid Input binary matrix (0 = water, 1 = land).
     * @return Maximum distance, or -1 if the grid has only water or only land.
     */
    int maxDistance(vector<vector<int>> &grid) {
        // Collect coordinates of water and land cells.
        vector<pair<int, int>> water;
        vector<pair<int, int>> land;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    water.push_back({i, j});
                } else {
                    land.push_back({i, j});
                }
            }
        }
        // Edge case: no water or no land.
        if (water.empty() || land.empty())
            return -1;

        int mx = -1; // stores the answer
        // For each water cell, find the closest land cell.
        for (const auto &w : water) {
            int mn = INT_MAX; // minimum distance for this water cell
            for (const auto &l : land) {
                int dst = abs(w.first - l.first) + abs(w.second - l.second);
                mn = min(mn, dst);
            }
            mx = max(mx, mn);
        }
        return mx;
    }
};