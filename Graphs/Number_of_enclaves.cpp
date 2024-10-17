int dx[]={-1,0,+1,0};
int dy[]={0,+1,0,-1};

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        queue<pair<int,int>> q;   // Storing current BFS level cells
        q.push({row, col});
        vis[row][col]=1;
        while (!q.empty()) {
            int x=q.front().first;       // current row
            int y=q.front().second;      // current column
            q.pop();
            for (int i=0; i<4; i++) {
                int nx=x+dx[i];   // new row index
                int ny=y+dy[i];   // new column index
                if (nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && grid[nx][ny]==1) {
                    q.push({nx,ny});   // new cell
                    vis[nx][ny]=1;     // visited
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Traverse boundary element
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i==0 || j==0 || i==n-1 || j==m-1) {
                    // If there is land, start BFS
                    if (grid[i][j]==1 && vis[i][j]==0) {
                        bfs(i,j,grid,vis,n,m);  // Starting from boundary land cells
                    }
                }
            }
        }

        int ans=0;
        // Counting unvisited land cells
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1 && vis[i][j]==0) {  // Land and unvisited
                    ans++;
                }
            }
        }
        return ans;
    }
};