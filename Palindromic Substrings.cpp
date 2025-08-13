expand around center technique

class Solution {
public:
    int expand(string &s, int l, int r){
        int cnt = 0, n = s.length();

        while(l >= 0 && r < n && s[l] == s[r]){
              cnt++;
              l--;
              r++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;

        for(int center = 0;center<n;center++){
            res += expand(s,center,center);
            res += expand(s,center,center+1);
        }

        return res;
    }
};
