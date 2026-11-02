class Solution {
public:

int sol(int ind,int amount,vector<int> &c,vector<vector<int>> &dp)
{
    if(amount==0) return 1;
    if(ind<0) return 0;
    

    if(ind==0 && c[ind]==amount) return 1;

    if(dp[ind][amount]!=0) return dp[ind][amount];

    int nottake=sol(ind-1,amount,c,dp);

    int take=0;
    if(c[ind]<=amount)
    {
        take=sol(ind,amount-c[ind],c,dp);
    }

    return dp[ind][amount]=nottake+take;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        return sol(n-1,amount,coins,dp);
    }
};
