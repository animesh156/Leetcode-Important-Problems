// optimal one Greedy Approach O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int curEnd = 0, maxReach = 0, cnt = 0;
        for(int i=0;i<n-1;i++){
            maxReach = max(maxReach, i + nums[i]);
            if(i == curEnd){
                cnt++;
                curEnd = maxReach;
            }
        }
        return cnt;
    }
};

// brute force dp with memo O(n^2)  
class Solution {
public:
    int f(int ind,vector<int> & nums, vector<int> &dp){
        if(ind >= nums.size() - 1) return 0;
        if(dp[ind] != -1) return dp[ind];
        int minJump = INT_MAX;
        for(int jump = 1;jump<=nums[ind];jump++){
           int next = ind + jump;
           if(next < nums.size()){
            int steps = f(next,nums,dp);
            if(steps != INT_MAX){
                minJump = min(minJump, steps + 1);
            }
           }
        }
        return dp[ind] = minJump;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};
