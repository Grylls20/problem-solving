int dx[] = {-1, 0, +1, 0}; 
int dy[] = {0, +1, 0, -1}; 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(); 
	    int m=mat[0].size(); 
	    vector<vector<int>> vis(n, vector<int>(m,0));     // Visited matrix
	    queue<pair<pair<int,int>, int>> q;       // points,steps
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {        // BFS
	            if(mat[i][j]==0) {
	                q.push({{i,j},0}); 
	                vis[i][j]=1; 
	            } else {
	                vis[i][j]=0;          // unvisited
	            }
	        }
	    }
        vector<vector<int>> ans(n, vector<int>(m,0));    // Matrix containing distance
	    while(!q.empty()) {
	        int x=q.front().first.first; 
	        int y=q.front().first.second; 
	        int dist=q.front().second; 
	        q.pop(); 
	        ans[x][y]=dist; 
	        for(int i=0; i<4; i++) {
	            int nx=x+dx[i], ny=y+dy[i]; 
	            // check for valid unvisited cell
	            if (nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0) {
                vis[nx][ny]=1;
                q.push({{nx, ny}, dist+1});
                }
	        }
	    }
	    return ans;
    }
};