// sliding window TC :- O(m +n)
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

// brute force O(n^3)

class Solution {
public:
    bool isValid(string &sub, unordered_map<char,int> &tCnt) {
        unordered_map<char,int> sCnt;
        for(auto ch : sub) sCnt[ch]++;

        for(auto it : tCnt) {
            if(sCnt[it.first] < it.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int minLen = INT_MAX;
        string ans = "";

        unordered_map<char,int> tCnt;

        for(auto ch : t) tCnt[ch]++;

        for(int i=0;i<s.length();i++) {
            for(int j= i;j<s.length();j++) {
                string sub = s.substr(i,j-i+1);
                if(isValid(sub,tCnt)) {
                    if(sub.length() < minLen) {
                        minLen = sub.length();
                        ans = sub;
                    }
                }
            }
        }

        return ans;
    }
};
