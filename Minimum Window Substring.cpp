class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> tCount;
        for(auto ch : t) tCount[ch]++;

        unordered_map<char,int> sCount;
        int minStart = 0;
        int minLen = INT_MAX;
        int matched = 0;
        int left = 0, right = 0;

        while(right < s.size()) {
            char ch = s[right];
            sCount[ch]++;

            if(tCount.count(ch) && sCount[ch] <= tCount[ch]) matched++;

            while(matched == t.size()) {
                if((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                sCount[s[left]]--;
                if(tCount.count(s[left]) && sCount[s[left]] < tCount[s[left]]) {
                    matched--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart,minLen);
    }
};
