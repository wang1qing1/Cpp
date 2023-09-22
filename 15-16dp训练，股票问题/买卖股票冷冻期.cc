class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        //1.创建dp表
        vector<vector<int>> dp(n,vector<int>(3));
        //2.初始化
        dp[0][0]=-prices[0];
 
        //3.填表
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][1]-prices[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][2],dp[i-1][1]);
            dp[i][2]=dp[i-1][0]+prices[i];
        }
        //4.确认返回值
        return max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    }
};