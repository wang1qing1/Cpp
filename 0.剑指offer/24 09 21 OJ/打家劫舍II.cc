class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> f(n);
        vector<int> g(n);
        f[0]=0;
        g[0]=nums[0];
        for(int i=1;i<n-1;i++)
        {
            f[i]=max(g[i-1],f[i-1]);
            g[i]=f[i-1]+nums[i];
        }
        int ret1= max(g[n-2],f[n-2]);
        f[1]=0;
        g[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            f[i]=max(g[i-1],f[i-1]);
            g[i]=f[i-1]+nums[i];
        }
        int ret2= max(g[n-1],f[n-1]);
        return max(ret1,ret2);
    }
};