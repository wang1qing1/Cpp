class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m=obstacleGrid.size();
        size_t n=obstacleGrid[0].size();
        vector<vector<int>> dp;
        dp.resize(m+1,vector<int>(n+1,0));
         dp[0][1]=1;

        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(obstacleGrid[i-1][j-1]==0)
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[m][n];
    }
};