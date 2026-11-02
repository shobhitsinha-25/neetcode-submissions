class Solution {
public:

int sol(int ind,vector<int> &nums,int &target,int expressionsum,vector<vector<int>> &dp,int sum)
{
    if(ind<0)
    {
        return target==expressionsum?1:0;
    }

    if(dp[ind][expressionsum+sum]!=-1) return dp[ind][expressionsum+sum];

    int negative=sol(ind-1,nums,target,expressionsum-nums[ind],dp,sum);

    int positive=sol(ind-1,nums,target,expressionsum+nums[ind],dp,sum);

    return dp[ind][expressionsum+sum]= negative+positive;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int expressionsum=0;
        int sum = 0;
        for (int x : nums) sum += x;
        vector<vector<int>> dp(
            n, vector<int>(2 * sum + 1, -1)
        );

        return sol(n-1,nums,target,expressionsum,dp,sum);
    }
};
