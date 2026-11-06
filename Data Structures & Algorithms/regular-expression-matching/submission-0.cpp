class Solution {
public:

    bool sol(int i, int j, string &s, string &p,
             vector<vector<int>> &dp) {

        if(i < 0 && j < 0) return true;

        if(j < 0) return false;

        // Pattern can still match an empty string
        if(i < 0) {
            if(p[j] == '*')
                return sol(i, j-2, s, p, dp);

            return false;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(p[j] == '*') {

            // Zero occurrences
            bool nottake = sol(i, j-2, s, p, dp);

            // One or more occurrences
            bool take = false;

            if(p[j-1] == '.' || p[j-1] == s[i]) {
                take = sol(i-1, j, s, p, dp);
            }

            return dp[i][j] = (take || nottake);
        }

        if(p[j] == '.' || s[i] == p[j]) {
            return dp[i][j] = sol(i-1, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return sol(n-1, m-1, s, p, dp);
    }
};