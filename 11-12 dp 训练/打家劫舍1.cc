class Solution {
public:
    int massage(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        //1.创建dp表
        vector<int> f(n,0);
        vector<int> g(n,0);

        //2.初始化
        f[0]=nums[0];
        g[0]=0;

        //3.填表
        for(int i=1;i<n;i++)
        {
            f[i]=g[i-1]+nums[i];
            g[i]=max(g[i-1],f[i-1]);
        }
        
        //4.确定返回值
        return max(f[n-1],g[n-1]);
    }
};