// TC will be K * (2 ^ t),  where t will be target / min(c), SC will be (2 ^ t)

class Solution {
public:
    void f(int ind, vector<int>& c, int tar, vector<int>& cur, vector<vector<int>> &res) {
        if(ind == c.size()) {
            if(tar == 0) res.push_back(cur);
            return;
        }

        if(c[ind] <= tar) {
            cur.push_back(c[ind]);
            f(ind, c, tar - c[ind], cur, res);
            cur.pop_back();
        }

        f(ind + 1, c, tar, cur, res);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
       vector<int> cur;
       vector<vector<int>> res;
       f(0, c, target, cur, res);
       return res;
    }
};


// with early pruning

class Solution {
public:
    void f(int ind, vector<int>& c, int tar, vector<int>& cur, vector<vector<int>> &res) {
           
            if (tar == 0) {
            res.push_back(cur);
            return;
        }


        for(int i=ind;i<c.size();i++) {
            if(c[i] > tar) break;
            cur.push_back(c[i]);
            f(i, c, tar - c[i], cur, res);
            cur.pop_back();
        }
       
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
       vector<int> cur;
       vector<vector<int>> res;
       sort(c.begin(), c.end());
       f(0, c, target, cur, res);
       return res;
    }
};
