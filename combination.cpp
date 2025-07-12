class Solution {
public: 
    void f(int start, int n, int k, vector<vector<int>> &ans, vector<int>&cur){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }

        for(int i=start;i<= n - (k - cur.size()) + 1;i++){
            cur.push_back(i);
            f(i+1,n,k,ans,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        f(1,n,k,ans,cur);
        return ans;
    }
};
