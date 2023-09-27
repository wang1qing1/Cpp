class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();

        // 1.创建 dp 表
        vector<int> f(n+1,0);
        vector<int> g(n+1,0);

        // 2.初始化
        // 3.填表
        int ret=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            if(nums[i-1]>0)
            {
                f[i]=max(1,f[i-1]+1);
                if(g[i-1])
                {
                    g[i]=max(0,g[i-1]+1);
                }
                else
                {
                    g[i]=0;
                }
            }
            else if(nums[i-1]<0)
            {
                if(g[i-1])
                {
                    f[i]=max(0,g[i-1]+1);
                }
                else
                {
                    f[i]=0;
                }
                g[i]=max(1,f[i-1]+1);
            }
            else
            {
                f[i]=g[i]=0;
            }
            ret=max(ret,f[i]);
        }
        return ret;
    }
};