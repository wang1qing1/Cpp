class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        vector<int> dp(bamboo_len+1);
        //dp[i]......最大值
        if(bamboo_len==3)return 2;
        for(int i=1;i<=bamboo_len;i++)dp[i]=i;
        for(int i=1;i<=bamboo_len;i++)
        {
            for(int j=1;j<i;j++)
            {
                dp[i]=max(dp[i-j]*dp[j],dp[i]);
            }
        }
        return dp[bamboo_len];
    }
};

// 12
// 3*3*3*3=81

//11
// 3 3 3 2=54
