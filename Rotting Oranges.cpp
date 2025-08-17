class Solution {
public:
     vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int minTime = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,pair<int,int>>> q;
          vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;

             minTime = max(minTime, time);

            for(auto dir : dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc] && grid[nr][nc] == 1){
                    q.push({time + 1, {nr, nc}});
                    grid[nr][nc] = 2;
                     vis[nr][nc] = true;
                }
            }

        }

      
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                  return -1;
                }
            }
        }

        return minTime;
  
    }
};
