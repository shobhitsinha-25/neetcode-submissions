
class Solution {
public:
    bool sol(int ind, vector<int>& nums, int target,
             vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind < 0) return false;

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        bool nottake = sol(ind - 1, nums, target, dp);

        bool take = false;
        if (nums[ind] <= target) {
            take = sol(ind - 1, nums,
                       target - nums[ind], dp);
        }

        return dp[ind][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );

        return sol(n - 1, nums, target, dp);
    }
};
