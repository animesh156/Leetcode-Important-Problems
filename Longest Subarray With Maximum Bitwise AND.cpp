class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(),nums.end());  //maxVal as doiing & on multiple element will be always be less than maxlelement between them so max & value willl be maxVal in the array so we just count the max consective len of that subbary wherre all value is eequal to maxVal
        int maxLen = 0;
        int curLen = 0;
        for(auto num : nums){
              if(num == maxVal){
                curLen++;
                maxLen = max(maxLen,curLen);
              }
              else {
                curLen = 0;
              }
        }
        return maxLen;
    }
};
