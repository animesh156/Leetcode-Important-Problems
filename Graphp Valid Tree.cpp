#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (!dfs(adjNode, node, adj, vis))
                return false;
        }
        else if (parent != adjNode)
        {
            return false;
        }
    }

    return true;
}

bool validTree(int n, vector<vector<int>> &edges)
{
    if (edges.size() != n - 1)
        return false;

    vector<vector<int>> adj(n);

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(n, false);

    if (!dfs(0, -1, adj, vis))
        return false;

    for (auto it : vis)
    {
        if (!it)
            return false;
    }

    return true;
}

// Example usage
int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}};
    cout << (validTree(n, edges) ? "Yes" : "No") << endl;
    return 0;
}
