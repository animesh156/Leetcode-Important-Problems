class Solution {
public:
     int find( vector<int> adj[],int n){

        vector<int> dist(n, 1e9);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int nei : adj[node]) {
                if (dist[nei] > dist[node] + 1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }

        return dist[n - 1] == 1e9 ? -1 : dist[n - 1];
        
     }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];

        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
         vector<int> ans;
        for(auto it : queries){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            ans.push_back(find(adj,n));
        }
       return ans;
    }
};
