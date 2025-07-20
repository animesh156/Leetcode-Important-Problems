// sliding window soln

class Solution {
public:
     int f(vector<int>& nums, int k) {
        if(k < 0) return 0;
       int res = 0, i  = 0, j = 0;
        int sum = 0;

       while(j < nums.size()){
         sum += nums[j];

        while(sum > k){
            sum -= nums[i];
            i++;
        }

        res += (j - i + 1);
        j++;
       }

       return res;
   }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal) - f(nums,goal - 1);
    }
};




// map + prefix sum soln
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
