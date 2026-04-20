# Clone Graph

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.

### Complexity
- **Time Complexity**: O(V + E), where V = vertices and E = edges
- **Space Complexity**: O(V) for the visited map

---
### Approach
Use BFS or DFS with a hash map that maps each original node to its cloned copy. When visiting a node, create its clone if it hasn't been cloned yet, then recursively/iteratively clone all its neighbors. The map prevents infinite loops in cyclic graphs.
