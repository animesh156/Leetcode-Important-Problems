class Solution {
   
    class DisjointSet {
        vector<int> parent, size;

    public:
        DisjointSet(int n) {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUpar(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findUpar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if (ulp_u == ulp_v) return;

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (ds.findUpar(u) == ds.findUpar(v)) {
               
                return edge;
            }

            ds.unionBySize(u, v);
        }

        return {};
    }
};
