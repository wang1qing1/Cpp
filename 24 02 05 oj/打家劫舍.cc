class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n+1,0);
        vector<int> g=f;
        g[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            f[i]=max(f[i-1],g[i-1]);
            g[i]=f[i-1]+nums[i-1];
        }
        return max(f[n],g[n]);
    }
};