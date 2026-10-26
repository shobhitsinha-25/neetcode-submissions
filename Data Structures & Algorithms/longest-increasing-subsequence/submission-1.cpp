class Solution {
public:
    int sol(int ind, vector<int>& nums, int lastelement,
            vector<vector<int>>& dp) {
        if (ind < 0) return 0;

        if (dp[ind][lastelement] != -1)
            return dp[ind][lastelement];

        int nottake = sol(ind - 1, nums, lastelement, dp);

        int take = 0;

        if (lastelement == nums.size() ||
            nums[ind] < nums[lastelement]) {
            take = 1 + sol(ind - 1, nums, ind, dp);
        }

        return dp[ind][lastelement] = max(nottake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return sol(n - 1, nums, n, dp);
    }
};