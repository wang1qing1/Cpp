class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int subarrayProductK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,1));
        int ret=0;
        for(int j=1;j<=n;j++)
        {
            for(int i=j;i>=1;i--)
            {
                if(i==j)dp[i][j]=nums[i-1];
                else if(j-i==1)dp[i][j]=nums[i-1]*nums[j-1];
                else if(j-i>1)dp[i][j]=dp[i+1][j-1]*nums[i-1]*nums[j-1];
                if(dp[i][j]==k)
                {
                    ret++;
                }
            }
        }
        return ret;   
    }
};