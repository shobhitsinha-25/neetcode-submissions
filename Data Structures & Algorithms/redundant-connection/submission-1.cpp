
class Solution {
public:
vector<int> parent,rank;

int findparent(int x)
{
    if(parent[x]!=x)
    {
        parent[x]=findparent(parent[x]);
    }

    return parent[x];
}

bool unionfind(int u,int v)
{
    int pu=findparent(u);
    int pv=findparent(v);

    if(pu==pv) return false;

    if(rank[pu]>rank[pv]) parent[pv]=pu;
    else if(rank[pv]>rank[pv]) parent[pv]=pu;
    else parent[pv]=pu;

    return true;
    

}




    /*bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& vis,
             set<pair<int,int>>& st) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            if(it == parent) continue;

            if(!vis[it]) {
                if(dfs(it, node, adj, vis, st)) {
                    st.insert({min(node,it), max(node,it)});
                    return true;
                }
            }
            else {
                st.insert({min(node,it), max(node,it)});
                return true;
            }
        }

        return false;
    }
*/

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        /*
        vector<vector<int>> adj(n + 1);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n + 1, 0);
        set<pair<int,int>> st;

        dfs(1, -1, adj, vis, st);

        // Check original edges in reverse order
        for(int i = edges.size() - 1; i >= 0; i--) {

            int u = edges[i][0];
            int v = edges[i][1];

            if(st.count({min(u,v), max(u,v)})) {
                return edges[i];
            }
        }
        */

        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }

        for(auto edge:edges)
        {
            if(!unionfind(edge[0],edge[1])) return edge;
        }

        return {};
    }
};
