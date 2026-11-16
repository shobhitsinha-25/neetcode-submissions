class Solution {
    int count=0;
public:
void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid,int m,int n)
{
    if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || grid[i][j]=='0') return;

    vis[i][j]=1;

    int delrow[]={0,1,0,-1};
    int delcol[]={1,0,-1,0};

    for(int x=0;x<4;x++)
    {
        int nrow=i+delrow[x];
        int ncol=j+delcol[x];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]) dfs(nrow,ncol,vis,grid,m,n);
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,vis,grid,m,n);
                    count++;
                } 
            }
        }

        return count;
    }
};
