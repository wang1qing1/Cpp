class Solution {
public:

int massage(vector<int>& nums,int left,int right) {
        int n=nums.size();
        if(n==0) return 0;
        //1.创建dp表
        vector<int> f(n,0);
        vector<int> g(n,0);

        //2.初始化
        f[left]=nums[left];
        g[left]=0;

        //3.填表
        for(int i=left;i<=right;i++)
        {
            f[i]=g[i-1]+nums[i];
            g[i]=max(g[i-1],f[i-1]);
        }
        
        //4.确定返回值
        return max(f[right],g[right]);
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(nums[0]+massage(nums,2,n-2),massage(nums,1,n-1));

    }
};