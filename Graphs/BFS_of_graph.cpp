//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        queue<int> q;
        int V=adj.size();
        vector<int> bfs, vis(V,0); // To store BFS traversal result and a visited array to mark visited nodes
        q.push(0);
        vis[0]=1;
        while(!q.empty()) {
            int node=q.front(); // Get front node from queue
            q.pop();
            bfs.push_back(node);  // Add current node to BFS 
            for (auto it: adj[node]) {
                // If  neighbor is not visited, pushing it into queue and marking it visited
                if(!vis[it]) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends