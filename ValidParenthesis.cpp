class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') star.push(i);
            else {
                if(star.empty() && open.empty()) return false;
                if(!open.empty()) open.pop();
                else star.pop();
            }
        }

        while(!open.empty() && !star.empty()){
            if(open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }

        return open.empty();
    }
};

// greedy approach TC:- O(n), SC:- O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;
        int len = s.length() - 1;

        for(int i=0;i<=len;i++){
            if(s[i] == '(' || s[i] == '*') open++;
            else open--;

            if(s[len - i] == ')' | s[len - i] == '*') close++;
            else close--;

            if(open < 0 | close < 0) return false;
        }

        return true;
    }
};
