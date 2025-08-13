class Solution {
public:
    int startInd = -1, maxLen = 0;

    void expand(string &s, int l, int r){
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }

        int len = r - l - 1;
        if(len > maxLen){
            maxLen = len;
            startInd = l + 1;
        }
    }

    string longestPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }

        return s.substr(startInd, maxLen);
    }
};
