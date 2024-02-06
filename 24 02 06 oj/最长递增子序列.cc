class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,1);
        int ret=1;
        for(int i=2;i<=n;i++)
        {
            int tmp=0;
            for(int j=i-1;j>=1;j--)
            {
                if(nums[j-1]<nums[i-1]) 
                {
                    tmp=max(tmp,dp[j]);
                }
            }
            dp[i]=tmp+1;
            ret=max(ret,dp[i]);            
        }
        return ret;

    }
};