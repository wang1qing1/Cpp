class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
       
        int m=grid.size();
        int n=grid[0].size();
        //1.创建dp表//2.初始化表
        vector<vector<short>> dp(m+1,vector<short>(n+1,0));

        //3.填表
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }

        //4.确定返回值
        return dp[m][n];

    }
};