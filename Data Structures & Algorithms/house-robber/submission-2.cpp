class Solution {
public:
int sol(int ind,vector<int> &dp,vector<int> &nums)
{

    if(ind<0) return 0;
    if(ind==0) return nums[ind];

    if(dp[ind]!=-1) return dp[ind];

    int nottake=0+sol(ind-1,dp,nums);
    int take=nums[ind]+sol(ind-2,dp,nums);

    return dp[ind]=max(nottake,take);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return sol(n-1,dp,nums);
    }
};
