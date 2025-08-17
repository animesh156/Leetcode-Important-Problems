class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state, vector<int> &res) {
        if(state[node] == 1) return false;
        if(state[node] == 2) return true;

        state[node] = 1;
        for(auto adjNode : adj[node]) {
            if(!dfs(adjNode,adj,state,res)) return false;
        }

        state[node] = 2;
        res.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);

        for(auto it : p){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> res;

        for(int i=0;i<numCourses;i++){
            if(state[i] == 0) {
                if(!dfs(i,adj,state,res)) return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
