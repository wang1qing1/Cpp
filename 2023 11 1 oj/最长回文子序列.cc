class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,1));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(j-i==1)
                {   
                    if(s[j]==s[i]) dp[i][j]=2;
                    else dp[i][j]=1;
                }
                else if(j-i>1)
                {
                    if(s[j]==s[i]) dp[i][j]=2+dp[i+1][j-1];
                    else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};