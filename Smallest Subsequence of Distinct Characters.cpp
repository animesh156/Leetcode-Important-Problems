class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        vector<bool> vis(26,false);
        for(auto ch : s) freq[ch - 'a'];

        string ans = "";

        for(auto ch : s) {
            freq[ch - 'a']--;
            if(vis[ch - 'a']) continue;

            while(!ans.empty() && ch < ans.back() && freq[ans.back() - 'a'] > 0) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += ch;
            vis[ch - 'a'] = true;
        }

        return ans;
    }
};
