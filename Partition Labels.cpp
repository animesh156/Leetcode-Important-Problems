// greedy approach O(n) 
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


// merge interval approach

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastSeen(26,0), firstSeen(26,0);
        int partitionStart = 0, partitionEnd = 0;

        for(int i=0;i<s.length();i++) {
            lastSeen[s[i] - 'a'] = i;
        }

        vector<int> ans;

        for(int i=0;i<s.length();i++) {
            if(!firstSeen[s[i] - 'a']) {
                firstSeen[s[i] - 'a'] = i;
            }

            if(partitionEnd < firstSeen[s[i] - 'a']) {
              ans.push_back(partitionEnd - partitionStart + 1);
               partitionStart = i;
               partitionEnd =  i;
            }

            partitionEnd = max(partitionEnd, lastSeen[s[i] - 'a']);
        }

        if(partitionEnd - partitionStart + 1 > 0) {
            ans.push_back(partitionEnd - partitionStart + 1);
        }
        return ans;
    }
};
