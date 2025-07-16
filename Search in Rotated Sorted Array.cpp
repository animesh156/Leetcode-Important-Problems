class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;

        while(l <= h){
            int mid = (h + l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[l]) {
                if(target >= nums[l] && target < nums[mid]) h = mid - 1;
                else l = mid + 1;
            }
            else {
                if(target <= nums[h] && nums[mid] < target) l = mid + 1;
                else h = mid - 1;
            }
        }
        return -1;
    }
};
