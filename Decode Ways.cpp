class Solution {
public:
    int f(string & s, int ind, vector<int> &dp){
        if(ind == s.length()) return 1;
        if(s[ind] == '0') return 0;  // can't decode if contsains '0'
          if (dp[ind] != -1) return dp[ind]; 

        int ways = f(s, ind + 1, dp);

        if(ind + 1 < s.length()){
            int num = (s[ind] - '0') * 10 + (s[ind+1] - '0');
            if(num >= 10 && num <= 26){
                ways += f(s, ind + 2, dp);
            }
        }
        return dp[ind] = ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return f(s,0,dp);
    }
};
