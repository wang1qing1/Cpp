class Solution {
public:
    typedef vector<vector<int>> vvi;
    int dfs(vector<int>& len,int l,int r, vvi& dp)
    {
        int ans=0x3f3f3f3f;
        if(dp[l][r]!=-1)return dp[l][r];
        else
        {
            if(l>r)ans=0;
            else if(l==r)ans=len[r+1]-len[l-1]; 
            else 
            {
                for(int i=l;i<=r;i++)
                {
                    ans=min(ans,dfs(len,l,i-1,dp)+dfs(len,i+1,r,dp));
                }
                ans+=(len[r+1]-len[l-1]);
            }
        }
        dp[l][r]=ans;
        return ans;
    }
    int minCost(int m, vector<int>& cuts) {
        int n=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<int> len(n+2);
        len[0]=0;len[n+1]=m;
        for(int i=1;i<=n;i++)len[i]=cuts[i-1];    
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return dfs(len,1,n,dp);
    }
};