class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int des, int k) {
        

        vector<vector<pair<int,int>>> adj(n);

        for(auto it:f)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,int>> q;
        q.push({src,0});

        vector<int> dist(n,INT_MAX);

        dist[src]=0;
        int stops=0;

        while(!q.empty() && stops<=k)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int node=q.front().first;
                int distance=q.front().second;

                q.pop();
                for(auto it:adj[node])
                {
                    int adjnode=it.first;
                    int price=it.second;
                    int newcost=distance+price;
                    if(newcost<dist[adjnode])
                    {
                        q.push({adjnode,newcost});
                         dist[adjnode] = newcost;
                    } 
                }
            }
            stops++;
        }

        return (dist[des]==INT_MAX)?-1:dist[des];
    }
};
