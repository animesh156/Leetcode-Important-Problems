class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n < 3) return s;

        string result = "";
        result += s[0];
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;

            if(cnt <= 2) result += s[i];
        }

        return result;
       
    }
};
