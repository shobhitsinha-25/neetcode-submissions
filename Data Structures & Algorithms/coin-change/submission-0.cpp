class Solution {
public:

int sol(int ind,vector<int> &c,int target,vector<vector<int>> &dp)
{
    if(target==0) return 0;
    if(ind<0) return INT_MAX;

    if(dp[ind][target]!=-1) return dp[ind][target];
    

    int nottake=0+sol(ind-1,c,target,dp);

    int take=INT_MAX;
    if(c[ind]<=target)
    {
        int res=sol(ind,c,target-c[ind],dp);

        if(res!=INT_MAX){
            take=1+res;
        }
    }

    return dp[ind][target]= min(take,nottake);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        int ans=sol(n-1,coins,amount,dp);
        return (ans==INT_MAX)?-1:ans;
        //return dp[n-1];

    }
};
