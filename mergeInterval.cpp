class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<int> lastMerged = intervals[0];

        vector<vector<int>> ans;

        for(auto it : intervals){
            int s1 = it[0];
            int e1 = it[1];
            if(s1 <= lastMerged[1]){
                lastMerged[1] = max(lastMerged[1],e1);
            }
            else {
                ans.push_back(lastMerged);
                lastMerged = it;
            }
        }
        ans.push_back(lastMerged);
       return ans;
    }
};
