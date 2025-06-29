class Solution {
  private: 
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>&grid) {
        // mark it visited
        vis[i][j] = 1; 
        queue<pair<int,int>> q;
        q.push({i, j}); 
        int n=grid.size(); 
        int m=grid[0].size(); 
        while(!q.empty()) {
            int x=q.front().first; 
            int y=q.front().second; 
            q.pop(); 
            // traverse in adjacent index and mark them if it is land 
            for(int dx=-1; dx<=1; dx++) {
                for(int dy=-1; dy<=1; dy++) {
                    int nx=x+dx; 
                    int ny=y+dy; 
                    // neighbour row and column is valid, and is an unvisited land
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1' && !vis[nx][ny]) {
                        vis[nx][ny]=1; 
                        q.push({nx, ny}); 
                    }
                }
            }
        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        int ans=0; 
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // if not visited and is land
                if(!vis[i][j] && grid[i][j]=='1') {
                    ans++; 
                    bfs(i, j, vis, grid); 
                }
            }
        }
        return ans; 
    }
};