class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<short>> dp(n+1,vector<short>(m+1,0));
        text1.insert(0,"P");
        text2.insert(0,"P");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (int)dp[n][m];
    }
};