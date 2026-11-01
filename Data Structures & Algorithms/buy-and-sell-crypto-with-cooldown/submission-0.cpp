class Solution {
public:
int sol(int ind,vector<int> &p,int buy,vector<vector<int>> &dp)
{
    int n=p.size();
    if(ind>=n) return 0;

    if(dp[ind][buy]!=0) return dp[ind][buy];
    int profit=0;

    if(buy){
        profit=max((-p[ind]+sol(ind+1,p,0,dp)),(0+sol(ind+1,p,1,dp)));
    }

    else{
        profit=max((p[ind]+sol(ind+2,p,1,dp)),(0+sol(ind+1,p,0,dp)));
    }

    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        return sol(0,prices,1,dp);
    }
};
