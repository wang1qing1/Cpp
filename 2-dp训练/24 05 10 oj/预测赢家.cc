class Solution {
public:
    typedef  vector<vector<int>> vvi;
    int dfs(vector<int>& nums,int j,int i,vvi& dp)
    {
        int ans;
        if(dp[i][j]!=-1)return dp[i][j];
        else
        {
            if(i==j)ans=nums[i];
            else if(i-j==1)ans=max(nums[i],nums[j]);
            else if(i-j>1)
            {
                int ans1=nums[i]+min(dfs(nums,j,i-2,dp),dfs(nums,j+1,i-1,dp));
                int ans2=nums[j]+min(dfs(nums,j+1,i-1,dp),dfs(nums,j+2,i,dp));
                ans=max(ans1,ans2);
            }
        }
        dp[i][j]=ans;
        return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto e:nums)sum+=e;
        vvi dp(n,vector<int>(n,-1));
        int p1=dfs(nums,0,n-1,dp);
        int p2=sum-p1;
        return  p1>=p2;
    }
};