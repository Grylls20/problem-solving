//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// BFS
class Solution {
  public:
    bool bfs(int source, vector<int> adj[], vector<int>& vis) {
        vis[source]=1; 
        queue<pair<int,int>> q; // <source node,parent node>
        q.push({source, -1}); 
        while(!q.empty()) {
            int node=q.front().first; 
            int parent=q.front().second; 
            q.pop(); 
            for(auto it: adj[node]) {  // Checking adjacent node
                if(!vis[it]) {          // Not Visited
                    vis[it]=1; 
                    q.push({it, node}); 
                } 
                else if(parent!=it) {   // Visited 
                    return true; 
                }
            }
        }
        return false; 
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(bfs(i,adj,vis)) return true; 
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends