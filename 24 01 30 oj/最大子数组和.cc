class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        int ret=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ret=max(ret,dp[i]);
        }
        return ret;
    }
};