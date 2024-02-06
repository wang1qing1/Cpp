class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();//1
        int m=triangle.back().size();//
        vector<vector<int>> dp(n+1,vector<int>(m+2,0x3f3f3f3f));
        dp[1][1]=triangle[0][0];
        int ret=0x3f3f3f3f;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=triangle[i-1][j-1]+min(dp[i-1][j],dp[i-1][j-1]);
                if(i==n) ret=min(dp[i][j],ret);
            }
        } 
        return ret==0x3f3f3f3f?triangle[0][0]:ret;
    }
};