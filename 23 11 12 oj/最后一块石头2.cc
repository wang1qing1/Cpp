class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(auto e:stones)sum+=e;
        int tar=sum/2;
        stones.insert(stones.begin(),0);
        vector<vector<int>> dp(n+1,vector<int>(tar+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=tar;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=stones[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-stones[i]]+stones[i]);
            }
        }
        return sum-2*dp[n][tar];
    }
};