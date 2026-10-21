class Solution {
public:
int sol(int i,vector<int> &dp,vector<int> &cost)
{
    int n=cost.size();

    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];

    return dp[i]=cost[i]+min(sol(i+1,dp,cost),sol(i+2,dp,cost));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(sol(0,dp,cost),sol(1,dp,cost));
    }
};
