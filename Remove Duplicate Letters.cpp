class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> vis(26,false);
        for(auto ch : s){
            freq[ch - 'a']++;
        }

        string result = "";

        for(auto ch : s){
            freq[ch - 'a']--;
            if(vis[ch - 'a']) continue;

            while(!result.empty() && ch < result.back() && freq[result.back() - 'a'] > 0){
                vis[result.back() - 'a'] = false;
                result.pop_back();
            }

            result += ch;
            vis[ch - 'a'] = true;
        }


        return result;
    }
};
