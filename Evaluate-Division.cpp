class Solution {
public:
   
    bool dfs(string curr, string target, unordered_map<string, vector<pair<string, double>>>& adj,
               unordered_map<string, bool>& vis, double &cnt) {
        if (curr == target) return true;

        vis[curr] = true;

        for (auto& [neighbor, weight] : adj[curr]) {
            if (!vis[neighbor]) {
               double prev = cnt;
               cnt *= weight;
               if(dfs(neighbor,target,adj,vis,cnt)) return true;

               cnt = prev;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> adj;

       
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

       
        for (auto& query : queries) {
            string start = query[0];
            string end = query[1];

            if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_map<string, bool> vis;
            double cnt = 1.0;
            bool found = dfs(start, end, adj, vis,cnt);
            ans.push_back(found ? cnt : -1.0);
        }

        return ans;
    }
};
