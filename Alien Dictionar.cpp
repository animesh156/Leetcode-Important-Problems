class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char,int> indegree;

        // Step 1: Initialize indegree for all chars
        for (auto &w : words) {
            for (auto &ch : w) {
                indegree[ch] = 0;
            }
        }

        // Step 2: Build graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];

            // Invalid case: prefix issue
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }

            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break; // only first difference matters
                }
            }
        }

        // Step 3: Topological Sort (Kahn's Algorithm)
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0) q.push(it.first);
        }

        string order = "";
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            order += ch;

            for (auto nei : adj[ch]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        // Step 4: Check for cycle
        if (order.size() < indegree.size()) return "";
        return order;
    }
};
