class Solution {
public:
int sol(int ind,vector<int> &nums,vector<int> &dp)
{
    int n=nums.size();
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];
    
    int nottake=0+sol(ind-1,nums,dp);

    int take=nums[ind]+sol(ind-2,nums,dp);

    return dp[ind]=max(nottake,take);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);

        vector<int> v1;
        for(int i=0;i<n-1;i++)
        {
            v1.push_back(nums[i]);
        }

        vector<int> v2;
        for(int i=1;i<n;i++)
        {
            v2.push_back(nums[i]);
        }

        int ans1=sol(n-2,v1,dp1);
        int ans2=sol(n-2,v2,dp2);

        return max(ans1,ans2);

   }
};
