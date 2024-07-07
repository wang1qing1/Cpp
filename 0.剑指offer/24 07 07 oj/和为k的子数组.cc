class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1,0);
        int ret=0;
        //前缀和
        for(int i=1;i<dp.size();i++)
        {
            dp[i]=dp[i-1]+nums[i-1];
        }
        for(int i=1;i<dp.size();i++)
        {
            for(int j=i;j<dp.size();j++)
            {
                if(dp[j]-dp[i-1]==k)ret++;
            }
        }
        return ret;
    }
};