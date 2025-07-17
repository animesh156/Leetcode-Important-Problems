class Solution {
public: 
    bool isPossible(int capacity,vector<int>& weights, int days) {
        int curCapacity = capacity;
        int day = 1;
        for(int i=0;i<weights.size();i++){
            if(weights[i] > capacity) return false;
            if(curCapacity < weights[i]){
                 day++;
                 curCapacity = capacity;
            }

            curCapacity -= weights[i];
        }

        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);

        int ans = 0;

        while(l <= h){
           int mid = (h + l) / 2;
           if(isPossible(mid,weights,days)) {
            ans = mid;
            h = mid - 1;
           }
           else l = mid + 1;
        }

        return ans;
    }
};
