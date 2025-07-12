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
