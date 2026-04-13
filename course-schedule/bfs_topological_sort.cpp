#include <vector>
#include <queue>

using namespace std;

/*
 * Implementation of Course Schedule using Topological Sort (Kahn's Algorithm)
 *
 * Logic:
 * 1. Find all the parents (nodes having indegree as 0) and add them to a queue.
 * 2. Traverse Graph using BFS and on every visit, reduce the indegree of the child node.
 * 3. If a child's indegree becomes 0, add it to the queue.
 * 4. To confirm no cycle exists, the number of parents found and processed during 
 *    traversal must equal the total number of nodes in the graph.
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);//vector of length numCourses
        int courseList = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<courseList; i++) {
          int startNode = prerequisites[i][0];
          int endNode = prerequisites[i][1];
          courses[startNode].push_back(endNode);
          indegree[endNode]++; 
        }
        queue<int> q; //add all parents..
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()) {
            int parent = q.front();
            count++;
            q.pop();
            for(int i=0;i<courses[parent].size();i++) {
                int child = courses[parent][i];
                indegree[child]--;
                if(indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        return count == numCourses;
    }
};
