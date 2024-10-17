int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
class Solution {
public:
    int m,n;
    vector<vector<bool>> vis;
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        // cell is 'X' or already visited
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='X'||vis[i][j]) return;
        vis[i][j]=true;
        for (int k=0; k<4; k++) {
            int ni=i+dx[k];
            int nj=j+dy[k];
            dfs(board, ni, nj);
        }
    }

    bool isBoundary(int i, int j) {
        // Check cells on boundary 
        return i==0 || i==m-1 || j==0 || j==n-1;
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m=board.size();
        n=board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false)); // visited matrix
        // DFS for 'O' cells on boundary
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (isBoundary(i,j) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        // Marking unvisited 'O' cells as 'X'
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (!vis[i][j] && board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
    }
};