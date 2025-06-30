class Solution {
public:
    bool isDigit(string s){
        int ind = s.find(' ');
        if(s[ind + 1] >= '0' && s[ind + 1] <= '9') return true;
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits, letter;

        for(auto log : logs){
            if(isDigit(log)) digits.push_back(log);
            else letter.push_back(log);
        }

        sort(letter.begin(),letter.end(), [](auto &a, auto &b) {
           int ind1 = a.find(' ');
            int ind2 = b.find(' ');

            string id1 = a.substr(0, ind1);
            string id2 = b.substr(0, ind2);

            string content1 = a.substr(ind1 + 1);
            string content2 = b.substr(ind2 + 1);

            if (content1 == content2) return id1 < id2;
            return content1 < content2;
        });

        vector<string> ans;
        ans.insert(ans.end(), letter.begin(),letter.end());
        ans.insert(ans.end(), digits.begin(),digits.end());
        return ans;
    }
};
