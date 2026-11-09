class Solution {
public:

bool sol(int ind,vector<int> &nums,vector<int> &dp)
{
    int n=nums.size();
    if(ind>=n-1) return true;
    if(nums[ind]<0 && ind<n-1) return false;
    if(dp[ind]!=-1) return dp[ind];

    for(int i=1;i<=nums[ind];i++)
    {
        if(sol(ind+i,nums,dp)) return dp[ind]=1;
    }

    return dp[ind]=0;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        return sol(0,nums,dp);
    }
};
