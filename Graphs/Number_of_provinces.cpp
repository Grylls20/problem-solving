//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> edges(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(i==j) continue;
                if(adj[i][j]==1) {
                    edges[i].push_back(j); // Adding edge to adjacency list
                }
            }
        }
        int ans=0;
        vector<bool> vis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i,vis,edges);
            }
        }
        return ans;
    }
    void dfs(int node, vector<bool>&vis, vector<vector<int>>edges) {
        vis[node]=1;
        for(auto it: edges[node]) {
            if(!vis[it]) {
                dfs(it,vis,edges);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends