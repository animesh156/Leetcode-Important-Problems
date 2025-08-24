class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool dfs(int i, int j, vector<vector<char>>& board, int x, string &word, vector<vector<int>>& vis) {
        if (x == word.size()) return true; 

        for (auto &dir : dirs) {
            int nx = i + dir[0];
            int ny = j + dir[1];
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()
                && board[nx][ny] == word[x] && !vis[nx][ny]) {

                vis[nx][ny] = 1;
                if (dfs(nx, ny, board, x + 1, word, vis)) return true;
                vis[nx][ny] = 0; 
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int first = 0, last = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    first++;
                }
                else if(board[i][j] == word.back()) last++;
            }
        }

        if(first > last) reverse(word.begin(),word.end());
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (dfs(i, j, board, 1, word, vis)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};
