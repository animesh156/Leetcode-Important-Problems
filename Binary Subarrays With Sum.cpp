class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int,int> mp;
       mp[0] = 1;
       int sum = 0;
       int cnt = 0;

       for(auto num : nums){
        sum += num;
        if(mp.find(sum - goal) != mp.end()) cnt += mp[sum - goal];
        mp[sum]++;
       }

       return cnt;
    }
};
