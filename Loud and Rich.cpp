class Solution {
public:
     void dfs(unordered_map<int,vector<int>> &mp, vector<int> adj[],int node,int cur, vector<bool> &vis){

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                mp[cur].push_back(it);
                dfs(mp,adj,it,cur,vis);
            }
        }
       
     }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];

        for(auto it : richer){
            adj[it[1]].push_back(it[0]);
        }

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            vis[i] = true;
            mp[i].push_back(i);
            dfs(mp,adj,i,i,vis);
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            int minQuiet = INT_MAX, val = -1;
            for(auto it : mp[i]){
                if(quiet[it] < minQuiet){
                    minQuiet = quiet[it];
                    val = it;
                }
            }
            ans.push_back(val);
        }
       return ans;
    }
};
