class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ret=dp[0];
        for(int i=1;i<n;i++)
        {
            int tmp=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    if(dp[j]>tmp) tmp=dp[j];
            }
            dp[i]=tmp+1;
            ret=max(ret,dp[i]);
        }
        return ret;
    }
};