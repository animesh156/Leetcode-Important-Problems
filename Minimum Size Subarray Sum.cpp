class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j =0;
        int sum = 0;
        int maxLen = INT_MAX;
        while(j < nums.size()){
            sum += nums[j];
            while(sum >= target){
                maxLen = min(maxLen,j - i + 1);
                sum -= nums[i];
                i++;
            }
          
            j++;
        }
        return maxLen == INT_MAX ? 0 : maxLen;
    }
};
