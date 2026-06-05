#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * Finds the minimum number of buses required to travel from a source stop to a target stop.
     * This implementation uses std::map for visited tracking and a queue of pairs.
     * 
     * @param routes A list of bus routes, where routes[i] is a list of stops on the i-th route.
     * @param source The starting bus stop.
     * @param target The destination bus stop.
     * @return The minimum number of buses needed, or -1 if unreachable.
     */
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // Base case: if source and target stops are the same, 0 buses are needed
        if(source == target) return 0;
        
        // Adjacency list mapping stops to the indices of routes passing through them
        map<int, vector<int>> stopRoutes;
        
        // Visited tracking maps to keep track of visited routes and stops
        map<int,bool> visited;
        map<int,bool> visitedStop;
        
        // Build the adjacency list
        for(int i=0;i<routes.size();i++) {
            for(int j=0;j<routes[i].size();j++){
                int stop = routes[i][j];
                stopRoutes[stop].push_back(i);
            }
        }
        
        // BFS Queue storing pairs of {stop, bus_count}
        queue<pair<int,int>> q;
        q.push({source, 0});
        visitedStop[source] = true;
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            // Get all buses (routes) passing through the current stop
            vector<int> buses = stopRoutes[p.first];
            for(auto it=buses.begin(); it!= buses.end();it++) {
                // Skip if this bus route has already been traversed
                if(visited.find(*it) != visited.end()) {
                    continue;
                }
                visited[*it] = true;
                
                // Traverse all stops on this bus route
                for(auto kt=routes[*it].begin(); kt!=routes[*it].end();kt++) {
                    // If we reached the target stop, return the bus count + 1
                    if(*kt==target) return p.second + 1;
                    
                    // If the stop hasn't been visited yet, add it to the queue
                    if(visitedStop.find(*kt) == visitedStop.end()){
                        visitedStop[*kt] = true;
                        q.push({*kt, p.second + 1});
                    }
                }
            }
        }
        
        // Return -1 if there is no path between the source and target stops
        return -1;
    }
};
