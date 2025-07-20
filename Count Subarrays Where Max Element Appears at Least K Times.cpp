class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0, i = 0, j = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int maxCnt = 0;
        
       
        while(j < nums.size()){
           if(nums[j] == maxi) maxCnt++;

           while(maxCnt >= k){
              result += (n - j);    // as all subarray ending at j & after j will contribute to ans
              if(nums[i] == maxi) maxCnt--;
              i++;
           }
           j++;
        }
        
        return result;
       
    }
};
