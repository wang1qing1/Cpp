class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //1.创建dp表
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<short>> dp(m+1,vector<short>(n+2,32700));
        //2.初始化
        for(int i=0;i<n+2;i++)
        {
            dp[0][i]=0;
        }

        //3.填表

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+matrix[i-1][j-1];
            }
        }
        //4.确定返回值
        int ret=dp[m][1];
        for(int i=2;i<=n;i++)
        {
            if(ret>dp[m][i])
            {
                ret=dp[m][i];
            }
        }

        return ret;



    }
};