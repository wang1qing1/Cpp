class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m=d.size();
        int n=d[0].size();
        //1.创建dp表
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));

        //2.初始化
        dp[m][n-1]=dp[m-1][n]=1;

        //3.填表
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                //[i][j]->[i+1][j],[i][j+1]
                dp[i][j]=min(dp[i+1][j],dp[i+1][j])-d[i][j];
                //血量最小是1
                dp[i][j]=max(dp[i][j],1);
            }
        }
        //4.确认返回值
        return dp[0][0];
    }
};