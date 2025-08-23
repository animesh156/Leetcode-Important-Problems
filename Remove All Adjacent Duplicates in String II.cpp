class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;

        for(auto it : s){
            if(st.empty() || st.top().first != it){
                st.push({it,1});
            }
            else {
                auto [ch, f] = st.top();
                st.pop();
                if(f + 1 < k) st.push({ch, f + 1});
            }
        }

        string res = "";
        while(!st.empty()) {
            auto [ch, f] = st.top();
            st.pop();

            while(f--){
                res += ch;
            }
        }

        reverse(res.begin(),res.end());

        return res;
    }
};
