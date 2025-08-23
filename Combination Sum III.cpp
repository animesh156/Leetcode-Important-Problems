class Solution {
public:
    void f(int start, int k, int tar, vector<vector<int>> &res, vector<int> &path) {
        if(k == 0 && tar == 0) {
            res.push_back(path);
            return;
        }

        for(int i = start; i <= 9;i++) {
              if(i > tar || k <= 0) break;
              path.push_back(i);
              f(i + 1,k - 1, tar - i, res, path);
              path.pop_back();
            }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        f(1,k,n,res,path);
        return res;
    }
};
