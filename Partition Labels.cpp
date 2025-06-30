class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i] - 'a'] = i;
        }

        int partitionStart = 0, partitionEnd = 0;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            partitionEnd = max(partitionEnd, last[s[i] - 'a']);
            if(i == partitionEnd){
                ans.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return ans;
    }
};
