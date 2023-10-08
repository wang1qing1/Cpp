class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        //创建dp表
        vector<int> dp(n,0);
        int sum=0;
        for(int i=2;i<n;i++)
        {
            dp[i]=(nums[i-2]-nums[i-1])==(nums[i-1]-nums[i])?dp[i-1]+1:0;
            sum+=dp[i];
        }
        return sum;
    }
};