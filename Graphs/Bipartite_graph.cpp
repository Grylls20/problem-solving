class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        // Traverse adjacent nodes
        for (auto it: graph[node]) {
            // If unassigned to any set
            if (vis[it]==0) {
                // Assign the adjacent node to the opposite set
                vis[it]=-vis[node];
                // Recursively checking
                if (!dfs(it, vis, graph)) return false;
            }
            // If the adjacent node is in the same set
            else if (vis[it]==vis[node]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V, 0); 
        // For connected components
        for (int i=0; i<V; i++) {
            if (vis[i]==0) {
                // Start with assigning node i to set 1
                vis[i]=1;
                if (!dfs(i, vis, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};
