class Solution {
public:
    void f(string &tmp,int n,vector<string> &ans,int open, int close){
       if (open == n && close == n) {
            ans.push_back(tmp);
            return;
        }

        if (open < n) {
          tmp.push_back('(');
          f(tmp,n,ans,open+1,close);
          tmp.pop_back();
        }
           

        if (open > close) {
         tmp.push_back(')');
          f(tmp,n,ans,open,close+1);
          tmp.pop_back();
        }   
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        f(tmp,n,ans,0,0);
        return ans;
    }
};
