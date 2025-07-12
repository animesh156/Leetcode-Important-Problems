class Solution {
public:
    void f(int i, vector<int>& arr, int tar, vector<vector<int>>& ans, vector<int>& tmp) {
        if (tar == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int ind = i; ind < arr.size(); ind++) {
            if (arr[ind] > tar) break; 

            tmp.push_back(arr[ind]);
            f(ind, arr, tar - arr[ind], ans, tmp); 
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end()); 

        f(0, candidates, target, ans, tmp);

        return ans;
    }
};
