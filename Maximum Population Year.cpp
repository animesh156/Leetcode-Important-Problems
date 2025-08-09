class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;
        for(auto it : logs){
            events.push_back({it[0],1});
            events.push_back({it[1],-1});
        }

        sort(events.begin(),events.end(),[] (auto& a, auto& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int maxPop = 0, ans = 0, cur = 0;

        for(auto it : events){
            cur += it.second;
            if(cur > maxPop){
                maxPop = cur;
                ans = it.first;
            }
        }

        return ans;
    }
};
