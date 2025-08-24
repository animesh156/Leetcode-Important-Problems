class Solution {
public:
// tc will be O(n * (4 ^ n))  & sc will be O(n * ( 4 ^ n))
    unordered_map<char, string> mp;

    void f(int ind, vector<string> &ans, string &cur, string &digits){
        if(ind == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for(char c : mp[digits[ind]]) {   
            cur.push_back(c);
            f(ind + 1, ans, cur, digits);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string cur = "";
        f(0, ans, cur, digits);
        return ans;
    }
};
