class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    int dfs(vi& cuts,int l,int r,vvi& dp)
    {
        if(dp[l][r]!=-1)return dp[l][r];
        else 
        {
            int tmp=-1;
            if(l>r)tmp=0;
            else 
            {
                //k位置最后打包时的最大得分
                for(int k=l;k<=r;k++)
                {
                    tmp=max(tmp,dfs(cuts,l,k-1,dp)+dfs(cuts,k+1,r,dp)+cuts[k]*cuts[l-1]*cuts[r+1]);
                }
            }
            dp[l][r]=tmp;
        }
        return dp[l][r];
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vi cuts(n+2,1);
        for(int i=1;i<=n;i++)cuts[i]=nums[i-1];
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return dfs(cuts,1,n,dp);
    }
};