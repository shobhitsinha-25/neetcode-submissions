class Solution {
public:
bool dfs(int parent,int node,vector<vector<int>> &adj,vector<int> &vis)
{
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(!dfs(node,it,adj,vis)) return false;
        }
        else if(it!=parent) return false;
        
    }

    return true;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        
        
        if(!dfs(-1, 0, adj, vis))
            return false;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
                return false;
        }
        

        return true;

    }
};
