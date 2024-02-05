class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        for(int i=1;i<=amount;i++) dp[i]=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=coins[i-1];j<=amount;j++)
            {
                if(j-coins[i-1]>=0&&dp[j-coins[i-1]]!=-1)
                    dp[j]=min(dp[j]==-1?INT_MAX:dp[j],dp[j-coins[i-1]]+1);
            }
        }
        return dp[amount];
    }
};