class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k =-1;
        bool flag = true;
        for(int i=0;i<n;i++) {
            if(nums[i] != i) {
                k = k & nums[i];
                flag = false;
            }
        }
        if(flag) return 0;
        return k;
    }
};
