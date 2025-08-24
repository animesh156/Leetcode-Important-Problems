class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j =0;
        int maxLen = 0, cnt = 0;

        while(j < nums.size()) {
            if(nums[j] == 0) cnt++;

            while(cnt > 1){
                if(nums[i]== 0) cnt--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

// have to delete 1 ele at any cost
        return maxLen - 1;
    }
};
