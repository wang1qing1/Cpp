class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int n=frame.size();
        int m=frame[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+frame[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};