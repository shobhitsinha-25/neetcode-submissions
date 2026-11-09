class Solution {
public:

int sol(int ind,vector<int> &nums,vector<int> &dp)
{
    int n=nums.size();
    if(ind>=n-1) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int mini=INT_MAX;

    for(int i=1;i<=nums[ind];i++)
    {
        int ans=sol(i+ind,nums,dp);
        if(ans!=INT_MAX){
        mini=min(mini,ans+1);
        }
    }

    return dp[ind]=mini;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return sol(0,nums,dp);
        
    }
};
