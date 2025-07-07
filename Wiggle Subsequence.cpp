class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int up = 1, down = 1;

       // up: the length of the longest wiggle subsequence that ends in an upward difference (i.e., increasing).

// down: the length of the longest wiggle subsequence that ends in a downward difference (i.e., decreasing)."

        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]) up = down + 1;
            else if(nums[i] < nums[i-1]) down = up + 1;
        }

        return max(up,down);
    }
};
