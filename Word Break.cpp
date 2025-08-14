class Solution {
public:
    bool f(string &s,unordered_set<string> &st, int start,vector<int> &dp) {
        if(start == s.size()) return true;

        if(dp[start] != -1) return dp[start];

        for(int end = start + 1; end <= s.size();end++){
            string word = s.substr(start, end - start);
            if(st.count(word)){
                if(f(s,st,end,dp)) return dp[start] = 1;
            }
        }
        return dp[start] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1,-1);
        return f(s, st, 0, dp);
    }
};
