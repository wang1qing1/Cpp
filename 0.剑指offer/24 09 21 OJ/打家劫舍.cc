class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<short> f(n);
        vector<short> g(n);
        f[0]=0;
        g[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            f[i]=max(g[i-1],f[i-1]);
            g[i]=f[i-1]+nums[i];
        }
        return max(g[n-1],f[n-1]);
    }
};