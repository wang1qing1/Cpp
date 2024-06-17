class Solution {
public:
    int maxSales(vector<int>& sales) {
        int n=sales.size();
        vector<long long> dp(n);
        dp[0]=sales[0];
        long long ret=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+(long long)sales[i],(long long)sales[i]);
            ret=max(ret,dp[i]);
        }
        return ret;
        
    }
};