class Solution {
public:
    int uniquePaths(int m, int n) {
        //开辟dp表
        vector<vector<int>> dp;
        dp.resize(m+1,vector<int>(n+1,0));

        //初始化
        dp[0][1]=1;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
     }
};