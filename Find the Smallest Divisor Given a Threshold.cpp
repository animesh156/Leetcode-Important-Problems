class Solution {
public:
    bool possible(vector<int>& nums, int tar, int k) {
        int sum = 0;
        for(auto num : nums) {
            sum += ceil((double)num / (double)k);
        }
        return sum <= tar;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int h = *max_element(nums.begin(),nums.end());
        int l = 1;
        int ans = 0;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(possible(nums,threshold,mid)) {
               ans = mid;
               h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, h = arr.size()-1;

        while(l <= h) {
            int mid = l + (h-l) / 2;
            int missing = arr[mid] - (mid + 1); //missing no till index i, is arr[i] - (i+1)
            if(missing < k) l = mid + 1;
            else h = mid - 1;
        }

        return l + k;
    }
};
