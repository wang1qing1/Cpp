class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1));
        for(int i=0;i<m+1;i++) dp[0][i]=1;
        
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(s[j-1]==t[i-1]) dp[i][j]+=dp[i-1][j-1]%(1000000007);
                dp[i][j]+=dp[i][j-1]%(1000000007);
            }
        }
        return dp[n][m]%(1000000007);
    }
};