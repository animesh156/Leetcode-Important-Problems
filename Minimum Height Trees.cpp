// leaf trimming method of O(n) soln, in this MHT willl alaways liews in middle of longest path so create degree vector & put only those vector with degree == 1 till remianing > 2 as at ost 2 MHT woill exist in tree

class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        queue<int> q;
        int remaining = n;

        for(int i=0;i<n;i++){
            if(degree[i] == 1) q.push(i);
        }

        while(remaining > 2){
           int sz = q.size();
           remaining -= sz;
           while(sz--){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                degree[it]--;
                if(degree[it] == 1) q.push(it);
            }
           }
        }

       vector<int> ans;

       while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
       }
      
      return ans;
       
    }
};
