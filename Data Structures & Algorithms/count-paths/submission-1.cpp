class Solution {
public:
//int ans=0;

int sol(int i,int j,int row,int col,vector<vector<int>> &dp)
{
    if(i==0 && j==0){
        
        return 1;
    };

    if(i<0 || j<0) return 0;

    if(dp[i][j]!=0) return dp[i][j];
    int left=sol(i,j-1,row,col,dp);
    int up=sol(i-1,j,row,col,dp);

    return dp[i][j]=left+up;
}
    int uniquePaths(int m, int n) {
       
        vector<vector<int>> dp(m,vector<int>(n,0));
        return sol(m-1,n-1,m,n,dp);
        
    }
};
