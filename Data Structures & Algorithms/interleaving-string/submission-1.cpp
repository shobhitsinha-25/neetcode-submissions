class Solution {
public:

bool sol(int i,int j,string &s1,string &s2,string &s3,vector<vector<int>> &dp)
{

    if(i==s1.size() && j==s2.size()) return true;

    if(dp[i][j]!=-1) return dp[i][j];

    int k=i+j;
    int take1=0;
    int take2=0;

    if(i<s1.size() && s1[i]==s3[k])
    {
        take1=sol(i+1,j,s1,s2,s3,dp);
    }
    if(j<s2.size() && s2[j]==s3[k])
    {
        take2=sol(i,j+1,s1,s2,s3,dp);
    }

    return dp[i][j]= take1||take2;

}
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return 0;

        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,-1));

        return sol(0,0,s1,s2,s3,dp);
    }
};
