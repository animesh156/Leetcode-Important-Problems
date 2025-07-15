class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxFreq = 0, maxLen = 0;
        int i = 0, j = 0;
        while(j < s.length()){
              freq[s[j] - 'A']++;
              maxFreq = max(maxFreq,freq[s[j]-'A']);

              if((j - i + 1) - maxFreq > k){
                freq[s[i] - 'A']--;
                i++;
              }

              maxLen = max(maxLen,j - i + 1);
              j++;
        }

        return maxLen;
    }
};
