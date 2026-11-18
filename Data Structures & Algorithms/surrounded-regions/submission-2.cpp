class Solution {
public:
void dfs(int i,int j,int n,int m,vector<vector<char>> &board,vector<vector<int>> &vis)
{
    if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='X' || vis[i][j]) return;

    vis[i][j]=1;

    int delrow[]={0,1,0,-1};
    int delcol[]={1,0,-1,0};

    for(int x=0;x<4;x++)
    {
        int nrow=i+delrow[x];
        int ncol=j+delcol[x];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol])
        {
            dfs(nrow,ncol,n,m,board,vis);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        // chaeck for all the boundary 'O'
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O') 
            {
                dfs(0,j,n,m,board,vis);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(!vis[n-1][j] && board[n-1][j]=='O')
            {
                dfs(n-1,j,n,m,board,vis);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                dfs(i,0,n,m,board,vis);

            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,n,m,board,vis);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }


    }
};
