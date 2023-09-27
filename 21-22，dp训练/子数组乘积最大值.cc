class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        // 1.创建 dp 表
        vector<int> f(n+1,1);
        vector<int> g(n+1,1);
        // 2.初始化

        // 3.填表
        int ret=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            if(nums[i-1]>0)
            {
                f[i]=max(nums[i-1],f[i-1]*nums[i-1]);
                g[i]=min(nums[i-1],g[i-1]*nums[i-1]);
            }
            else
            {
                f[i]=max(nums[i-1],g[i-1]*nums[i-1]);
                g[i]=min(nums[i-1],f[i-1]*nums[i-1]);
            }
            ret=max(f[i],ret);
        }
        // 4.确定返回值

        return ret;
    }
};