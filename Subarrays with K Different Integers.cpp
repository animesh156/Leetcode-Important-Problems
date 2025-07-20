class Solution {
public:
   int f(vector<int>& nums, int k) {
    int res = 0, i  = 0, j = 0;
        unordered_map<int,int> mp;

       while(j < nums.size()){
        mp[nums[j]]++;

        while(mp.size() > k){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
        }

        res += (j - i + 1);
        j++;
       }

       return res;
   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};
