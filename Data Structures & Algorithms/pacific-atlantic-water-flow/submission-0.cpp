class Solution {
public:

void dfs(int i,int j,vector<vector<int>> &h,vector<vector<int>> &vis,int n,int m)
{
    vis[i][j]=1;

    int delrow[]={0,1,0,-1};
    int delcol[]={1,0,-1,0};

    for(int x=0;x<4;x++)
    {
        int nrow=i+delrow[x];
        int ncol=j+delcol[x];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && h[nrow][ncol]>=h[i][j] && !vis[nrow][ncol])
        {
            dfs(nrow,ncol,h,vis,n,m);
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();

        vector<vector<int>> p(n,vector<int>(m,0));
        vector<vector<int>> a(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            if(!p[0][j]) dfs(0,j,h,p,n,m);
        }

        for(int i=0;i<n;i++)
        {
            if(!p[i][0]) dfs(i,0,h,p,n,m);
        }

        for(int j = 0; j < m; j++) {
            if(!a[n-1][j])
                dfs(n-1, j, h, a, n, m);
        }

        for(int i = 0; i < n; i++) {
            if(!a[i][m-1])
                dfs(i, m-1, h, a, n, m);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] && p[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

return ans;

    }
};
