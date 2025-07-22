class Solution {
public:
    int f(int num,vector<int>& arr) {
        int sum = 0;
        for(auto it : arr){
            if(it >= num) sum += num;
            else sum += it;
        }
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int l = 0, h = *max_element(arr.begin(),arr.end());
        int ans = 0, minDif = INT_MAX;
        while(l <= h){
            int mid = l + (h-l)/2;
            int sum = f(mid,arr);
            int dif = abs(sum - target);
            if(dif < minDif || (dif == minDif && mid < ans)){
                ans = mid;
                minDif = dif;
            }

            if(sum < target) l = mid + 1;
            else h = mid - 1;
        }

        return ans;
    }
};
