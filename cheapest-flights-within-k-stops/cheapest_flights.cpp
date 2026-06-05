#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * @brief Finds the cheapest price from a source city to a destination city with at most k stops.
 *
 * The algorithm builds an adjacency list where each entry maps a start city to a list of
 * (neighbor, price) pairs. It then performs a BFS limited to k+1 levels (k stops means k+1 edges)
 * while keeping track of the best known price to each city. The queue stores pairs of
 * (current city, accumulated cost). When a cheaper price to a neighbor is discovered, we
 * push the neighbor onto the queue for further exploration.
 *
 * Time Complexity: O(E * K) – each edge can be relaxed at most k+1 times.
 * Space Complexity: O(V + E) for the adjacency list and the BFS queue.
 */
class Solution {
public:
    /**
     * @param n       Number of cities (0-indexed).
     * @param flights List of flights where each flight is [from, to, price].
     * @param src     Source city.
     * @param dst     Destination city.
     * @param k       Maximum number of stops allowed.
     * @return Minimum cost to reach dst within k stops, or -1 if impossible.
     */
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build adjacency list: start city -> list of (dest, price)
        unordered_map<int, vector<pair<int,int>>> adj;
        for (const auto& f : flights) {
            // f[0] = from, f[1] = to, f[2] = price
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        // 2. price[city] stores the cheapest known price to reach that city so far.
        unordered_map<int, int> price;

        // 3. BFS queue holds (city, accumulated cost) pairs.
        queue<pair<int,int>> q;
        q.emplace(src, 0);   // start from source with cost 0
        price[src] = 0;      // cheapest cost to reach src is 0

        int stops = 0; // number of edges explored so far (levels)

        // 4. Perform BFS level by level, each level corresponds to one additional stop.
        while (!q.empty() && stops <= k) {
            int sz = q.size(); // number of nodes at current level
            // Process all nodes in the current level before increasing the stop count.
            for (int i = 0; i < sz; ++i) {
                auto [city, cost] = q.front();
                q.pop();

                // Explore all outgoing flights from the current city.
                for (const auto& [next, w] : adj[city]) {
                    int newCost = cost + w; // cost to reach 'next' via this flight
                    // If we found a cheaper way to reach 'next', update and enqueue.
                    if (!price.count(next) || newCost < price[next]) {
                        price[next] = newCost;
                        q.emplace(next, newCost);
                    }
                }
            }
            ++stops; // move to next stop count
        }
        // Return the cheapest price to reach destination if it was discovered.
        return price.count(dst) ? price[dst] : -1;
    }
};
