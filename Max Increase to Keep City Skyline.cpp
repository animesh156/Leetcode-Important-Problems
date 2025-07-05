class Solution {
public:
    pair<int,int> findMax(int r, int c, vector<vector<int>>& grid) {
        int maxiRowEle = 0;
        for(int i=0;i<grid.size();i++) {
            maxiRowEle = max(maxiRowEle,grid[i][c]);
        }

        int maxiColEle = 0;
        for(int j=0;j<grid[0].size();j++) {
            maxiColEle = max(maxiColEle,grid[r][j]);
        }

        return {maxiRowEle, maxiColEle};
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int maxSum = 0;

        vector<int> rowMax(grid.size(),0);
        vector<int> colMax(grid[0].size(),0);

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                rowMax[i] = max(rowMax[i],grid[i][j]);
                colMax[j] = max(colMax[j],grid[i][j]);
            }
        }

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
               int allowedHeight = min(rowMax[i],colMax[j]);
               maxSum += (allowedHeight - grid[i][j]);
            }
        }
        return maxSum;
    }
};
