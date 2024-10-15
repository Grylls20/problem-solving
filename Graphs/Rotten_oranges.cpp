// Directions to move in grid (right, left, down, up)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size(), n=grid[0].size(), total=0; 
        queue<pair<int, int>> q; // rotten oranges positions
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int cnt=0, time=0;
        while(!q.empty()){
            int k=q.size();
            cnt+=k; 
            while(k--){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int i=0; i<4; ++i){
                    int nx=x+dx[i], ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue; // Check
                    grid[nx][ny]=2; // Rotting the fresh ones
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) time++;
        }
        if(total==cnt) return time;
        else return -1;

    }
};