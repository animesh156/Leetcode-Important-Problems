class Solution {
public:
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    void f(int start, string &s, vector<vector<string>> &ans, vector<string> &path) {
        if(start == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s,start,end)) {
                path.push_back(s.substr(start, end - start + 1));
                f(end + 1, s, ans, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        f(0,s,ans,path);
        return ans;
    }
};
