class Solution {
    int maxarea=0;
public:

void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis,int &currarea,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]) return;

    vis[i][j]=1;
    currarea+=1;

    int delrow[]={0,1,0,-1};
    int delcol[]={1,0,-1,0};

    for(int x=0;x<4;x++)
    {
        int nrow=i+delrow[x];
        int ncol=j+delcol[x];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
        {
            dfs(nrow,ncol,grid,vis,currarea,n,m);
        }
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int currarea=0;

                    dfs(i,j,grid,vis,currarea,n,m);
                    maxarea=max(maxarea,currarea);
                }
            }
        }

        return maxarea;
    }
};
