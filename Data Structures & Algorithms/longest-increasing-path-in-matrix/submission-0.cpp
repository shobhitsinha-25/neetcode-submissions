class Solution {
public:
int sol(int i,int j,vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &dp)
{
    //base case...
    

    if(dp[i][j]!=0) return dp[i][j];
    dp[i][j]=1;


    int delrow[]={0,1,0,-1};
    int delcol[]={1,0,-1,0};
    for(int d=0;d<4;d++)
    {
        int nrow=i+delrow[d];
        int ncol=j+delcol[d];
        if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m && matrix[i][j]<matrix[nrow][ncol])
        {
            dp[i][j]=max(dp[i][j],1+sol(nrow,ncol,matrix,n,m,dp));
        }

    }

    return dp[i][j];


}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                maxi = max(
                    maxi,
                    sol(i, j, matrix, n, m, dp)
                );
            }
        }
        return maxi;
    }
};
