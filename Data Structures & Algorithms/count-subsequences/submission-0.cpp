class Solution {
public:

int sol(int i,int j,string &s,string &t,vector<vector<int>> &dp)
{
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=0) return dp[i][j];

int nottake=0,take=0;
    if(s[i]==t[j])
    {
        take=sol(i-1,j-1,s,t,dp);
        nottake=sol(i-1,j,s,t,dp);
    }
    else nottake=sol(i-1,j,s,t,dp);

    return dp[i][j]= take+nottake;
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        return sol(n-1,m-1,s,t,dp);
    }
};
