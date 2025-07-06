class Solution {
public:
    void flipRow(vector<vector<int>>& grid,int i, int m) {
        for(int j=0;j<m;j++) {
            grid[i][j] = !grid[i][j];
        }
    }

    void flipCol(vector<vector<int>>& grid,int i, int n) {
         for(int j=0;j<n;j++) {
            grid[j][i] = !grid[j][i];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
           if(grid[i][0] == 0) {
            flipRow(grid,i,m);
           }
        }

         for(int j=1;j<m;j++) {
            int ones = 0;
            for(int i=0;i<n;i++) {
                if(grid[i][j] == 1) ones++;
            }

            if(ones < n - ones) {
                flipCol(grid,j,n);
            }  
        }

        int score = 0;
        for(int i=0;i<n;i++) {
            int rowVal = 0;
            for (int j = m - 1, p = 0; j >= 0; j--, p++) {
              if (grid[i][j] == 1) {
            rowVal += (1 << p); 
    }
}
            score += rowVal;
        }
        
        return score;
    }
};
