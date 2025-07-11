class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
       unordered_map<int,int> modCount;
       modCount[0] = 1;
       int cnt = 0;
       int prefixSum = 0;

       for(auto it : nums) {
        prefixSum += it;

        int mod = prefixSum % k ;
        if(mod < 0) mod += k;

        if(modCount.find(mod) != modCount.end()) cnt += modCount[mod];

        modCount[mod]++;
       }

        return cnt;
    }
};
