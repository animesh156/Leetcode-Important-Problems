class Solution {
public: 
    void f(int ind, vector<int>& nums, vector<vector<int>> &res){
        if(ind == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen;

        for(int i=ind;i<nums.size();i++){
            if(seen.count(nums[i])) continue;
            seen.insert(nums[i]);

            swap(nums[i],nums[ind]);
            f(ind+1,nums,res);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        f(0, nums,res);
        return res;
    }
};





class Solution {
public: 
    void f(vector<int>& nums, vector<vector<int>> &res, vector<int> &cur,vector<bool> &vis){
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            vis[i] = true;
            cur.push_back(nums[i]);
            f(nums,res,cur,vis);
            cur.pop_back();
            vis[i] = false;
        }

    }
       
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        vector<bool> vis(nums.size(),false);
        f(nums,res,cur,vis);
        return res;
    }
};
