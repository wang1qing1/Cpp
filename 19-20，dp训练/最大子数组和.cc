class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        //1.创建dp表
        //2.初始化

        vector<int> dp(n+1);
        //3.填表
        int ret=-0x3f3f3f3f;
        for(int i=1;i<n+1;i++)
        {
            dp[i]=max(nums[i-1],dp[i-1]+nums[i-1]);
            ret=max(ret,dp[i]);
        }        
        return ret;
    }
};