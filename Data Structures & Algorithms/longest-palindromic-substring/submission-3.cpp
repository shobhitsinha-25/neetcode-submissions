class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string r = s;
        reverse(r.begin(), r.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxi = 0;
        int endIndex = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == r[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    int len = dp[i][j];
                    int startS = i - len;
                    int startR = n - j;

                    // Ensure the matching substring is a palindrome
                    if (i - len == n - j) {
                        // Check matching positions in the original string
                        if (len > maxi) {
                            maxi = len;
                            endIndex = i;
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(endIndex - maxi, maxi);
    }
};