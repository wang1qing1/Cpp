class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        vector<int> dp(n,1);//初始化的时候必须是1,因为单个数字就是一个递增的序列
        dp[0]=1;
        int ret=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[j][1]<envelopes[i][1]&&envelopes[j][0]<envelopes[i][0]) 
                {
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            ret=max(ret,dp[i]);
        }
        return ret;
    }
};