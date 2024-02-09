class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size())return false;
        s1=' '+s1;
        s2=' '+s2;
        s3=" "+s3;
        vector<vector<int>> dp(n+1,vector<int>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            if(s1[i]==s3[i])dp[i][0]=true;
            else break;
        }
        for(int i=1;i<=m;i++)
        {
            if(s2[i]==s3[i])dp[0][i]=true;
            else break;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(dp[i][j-1]&&s2[j]==s3[i+j]||dp[i-1][j]&&s1[i]==s3[i+j])dp[i][j]=true;
            }
        }
        return dp[n][m];
    }
};