//超时
class Solution {
public:
    const int INF=0x3f3f3f3f;
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<double> dp(n);
        int ret=INF;
        for(int j=0;j<n;j++)
        {
            for(int i=j;i>=0;i--)
            {
                if(i==j)dp[i]=nums[i];
                else dp[i]=dp[i+1]+nums[i];
                if(dp[i]>=target)ret=min(ret,j-i+1);
            }
        }
        return ret==INF?0:ret;
     }
};
//超内存
class Solution {
public:
    const int INF=0x3f3f3f3f;
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int ret=INF;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<=j;i++)
            {
                if(i==j)dp[i][j]=nums[i];
                else dp[i][j]=dp[i][j-1]+nums[j];
                if(dp[i][j]>=target)ret=min(ret,j-i+1);
            }
        }
        return ret==INF?0:ret;
     }
};
//滑动窗口
class Solution {
public:
    const int INF=0x3f3f3f3f; 
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int n=nums.size();
        int sum=0;
        int  ret=INF;
        while(right<n)
        {
            if(sum<target)
            {
                sum+=nums[right++];
                while(sum>=target)
                {
                    ret=min(ret,right-left);
                    sum-=nums[left++];
                }
            }
        }
        return ret==INF?0:ret;
    }
};