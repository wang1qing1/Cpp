class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param features int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int minAnimalCount(vector<int>& fe, int target) {
        int n=fe.size();
        int m=target;
        vector<int> dp(m+1,0x3f3f3f3f);
        dp[0]=0;
        int ret=0x3f3f3f3f;
        for(int i=0;i<n;i++)
        {
            for(int j=fe[i];j<=m;j++)
            {
                if(j-fe[i]>=0)dp[j]=min(dp[j],dp[j-fe[i]]+1);
                if(j==m)ret=min(ret,dp[j]);
            }
        }
        return ret==0x3f3f3f3f?0:ret;
    }
};