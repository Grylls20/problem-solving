//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V=adj.size();
        int start = 0; // first node
        vector<int> ls, vis(V, 0); 
        dfs(start, adj, vis, ls); // Start DFS
        return ls; 
    }
  
   private: 
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &ls) {
        vis[node]=1; // Mark current node as visited
        ls.push_back(node); // Add it to the result list
        // Traverse all its neighbours
        for(auto it: adj[node]) {
            // If neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends