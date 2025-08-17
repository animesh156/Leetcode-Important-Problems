class Solution {
public:
     vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

      void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        int m = board.size(), n = board[0].size();
        vis[i][j] = true;

        for (auto dir : dirs) {
            int nx = i + dir[0];
            int ny = j + dir[1];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n 
                && !vis[nx][ny] && board[nx][ny] == 'O') {
                dfs(nx, ny, board, vis);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
         vector<vector<bool>> vis(m,vector<bool>(n,false));


         for(int i=0;i<m;i++) {
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i,0,board,vis);
            if(board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i,n-1,board,vis);
         }
         
          for(int j=0;j<n;j++) {
            if(board[0][j] == 'O' && !vis[0][j]) dfs(0,j,board,vis);
            if(board[m-1][j] == 'O' && !vis[m-1][j]) dfs(m-1,j,board,vis);
         }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                   } 
            }
        }
    }
};
