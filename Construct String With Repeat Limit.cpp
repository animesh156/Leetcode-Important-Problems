class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(auto ch : s) freq[ch - 'a']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i] > 0) pq.push(i);
        }

        string ans = "";

        while(!pq.empty()){
            int cur = pq.top();
            pq.pop();

            int use = min(freq[cur],repeatLimit);

            for(int i=0;i<use;i++) {
                ans += cur + 'a';
            }

            freq[cur] -= use;

            if(freq[cur] > 0){
                if(pq.empty()) break;

                int next = pq.top();
                pq.pop();

                ans += next + 'a';
                freq[next]--;

                if(freq[next] > 0) pq.push(next);

                pq.push(cur);
            }
        }
        return ans;
    }
};
