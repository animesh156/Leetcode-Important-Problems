class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        int m = heights.size(), n = heights[0].size();
        ocean[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

       
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);

        
        for (int i = 0; i < m; i++) dfs(i, n - 1, heights, atlantic);
        for (int j = 0; j < n; j++) dfs(m - 1, j, heights, atlantic);

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
