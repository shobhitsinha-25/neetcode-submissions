class Solution {
public:
int sol(int n,vector<int> &dp)
{
    if(n<0) return 0;
    if(n==0) return 1;

    if(dp[n]!=0) return dp[n];
    int first=sol(n-1,dp);
    int second=sol(n-2,dp);

    return dp[n]=first+second;
    
}
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        sol(n,dp);
        return dp[n];
    }
};
