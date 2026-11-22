class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();

        vector<int> vis(n,0);

// {weight,node}...
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});

        int ans=0,count=0;

        while(!q.empty() && count<n)
        {
            auto it=q.top();
            q.pop();

            int cost=it.first;
            int node=it.second;

            if(vis[node]) continue;

            ans+=cost;
            count++;
            vis[node]=1;

            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    int newcost=abs(p[node][0]-p[i][0])+abs(p[node][1]-p[i][1]);
                    q.push({newcost,i});
                }
            }
            
        }

        return ans;

    }
};
