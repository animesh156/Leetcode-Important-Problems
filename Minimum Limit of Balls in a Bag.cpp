class Solution {
public:
    bool isPossible(vector<int>& nums,int maxBalls, int maxOperations) {
        int totalOperations = 0;

        for(auto it : nums) {
           int operations = ceil(it/(double)maxBalls) - 1;
            totalOperations +=  operations;
            if(totalOperations > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int k) {
        int l =  1, h = *max_element(nums.begin(),nums.end());

        while(l < h) {
            int mid = l + (h-l) / 2;
            if(isPossible(nums,mid,k)) {
                h = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return  l;
    }
};
