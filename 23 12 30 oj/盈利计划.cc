class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        int c=group.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=c;i++)
        {
            for(int j=n;j-group[i-1]>=0;j--)
            {
                for(int k=m;k>=0;k--)
                {
                    if(j-group[i-1]>=0) dp[j][k]+=dp[j-group[i-1]][max(0,k-profit[i-1])];
                    dp[j][k]%=(1000000000+7);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        int c=group.size();
        vector<vector<vector<int>>> dp(c+1,vector<vector<int>>(n+1,vector<int>(m+1)));
        for(int i=0;i<=n;i++)dp[0][i][0]=1;
        for(int i=1;i<=c;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=m;k++)
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    if(j-group[i-1]>=0) dp[i][j][k]+=dp[i-1][j-group[i-1]][max(0,k-profit[i-1])];
                    dp[i][j][k]%=(1000000000+7);
                }
            }
        }
        return dp[c][n][m];
    }
};