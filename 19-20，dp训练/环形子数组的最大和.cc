class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();

        // 1.创建 dp 表
        vector<int> f(n+1);
        vector<int> g(n+1);

        //2.初始化
        f[0]=g[0]=0;

        //3.填表
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int sum=0;
        for(int i=1;i<n+1;i++)
        {
            int tmp=nums[i-1];
            f[i]=max(tmp,tmp+f[i-1]);
            maxsum=max(f[i],maxsum);
            g[i]=min(tmp,tmp+g[i-1]);
            minsum=min(g[i],minsum);
            sum+=tmp;
        }
        // 4.确定返回值
        return sum==minsum?maxsum:maxsum>sum-minsum?maxsum:sum-minsum;
    }
};