class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> cord;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) cord.push({i,j});
            }
        }

       

        while(!cord.empty())
        {
            auto [i,j]=cord.front();
            cord.pop();

            for(int x=0;x<4;x++)
            {
                int delrow[]={0,1,0,-1};
                int delcol[]={1,0,-1,0};

                int nrow=i+delrow[x];
                int ncol=j+delcol[x];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==INT_MAX)
                {
                    grid[nrow][ncol]=grid[i][j]+1;
                    cord.push({nrow,ncol});
                }
            }
        }

    }
};
