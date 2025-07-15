class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        int i = 0, j = 0;
        
        vector<int> ans;
        while(j < nums.size()){
            while(!dq.empty() && nums[j] > dq.back().first) {
                dq.pop_back();
            }

             dq.push_back({nums[j],j});

            if(j - i + 1 < k){
                j++;
            }
            else {
                while(!dq.empty() && dq.front().second < i) dq.pop_front();
                ans.push_back(dq.front().first);
                i++;
                j++;
            }
        }
        return ans;
    }
};
