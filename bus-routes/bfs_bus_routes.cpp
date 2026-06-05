#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * Finds the minimum number of buses required to travel from a source stop to a target stop.
     * 
     * @param routes A list of bus routes, where routes[i] is a list of stops on the i-th route.
     * @param source The starting bus stop.
     * @param target The destination bus stop.
     * @return The minimum number of buses needed, or -1 if unreachable.
     */
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // If the source and target are the same, no buses are needed.
        if (source == target) {
            return 0;
        }

        // Map each stop to the list of bus routes (by route index) that pass through it.
        unordered_map<int, vector<int>> stopToRoutes;
        for (int routeIdx = 0; routeIdx < routes.size(); ++routeIdx) {
            for (int stop : routes[routeIdx]) {
                stopToRoutes[stop].push_back(routeIdx);
            }
        }

        // Queue for level-by-level BFS: stores the bus stops.
        queue<int> q;
        q.push(source);

        // Keep track of visited bus routes to avoid traversing the same route multiple times.
        vector<bool> visitedRoutes(routes.size(), false);

        // Keep track of visited stops to avoid redundant exploration.
        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        int busCount = 0;

        // Standard level-by-level BFS traversal
        while (!q.empty()) {
            int levelSize = q.size();
            busCount++;

            for (int i = 0; i < levelSize; ++i) {
                int currStop = q.front();
                q.pop();

                // Get all bus routes passing through the current stop
                for (int routeIdx : stopToRoutes[currStop]) {
                    // Skip if we have already boarded this bus route
                    if (visitedRoutes[routeIdx]) {
                        continue;
                    }
                    visitedRoutes[routeIdx] = true;

                    // Traverse all stops on this bus route
                    for (int nextStop : routes[routeIdx]) {
                        // If we reach our target, return the current number of buses taken
                        if (nextStop == target) {
                            return busCount;
                        }

                        // If the stop hasn't been visited, add it to the queue
                        if (visitedStops.find(nextStop) == visitedStops.end()) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        // Return -1 if there is no path between the source and target stops
        return -1;
    }
};
